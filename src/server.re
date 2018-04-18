[@bs.module "react-apollo"]
external getDataFromTree : ReasonReact.reactElement => Js.Promise.t(unit) =
  "getDataFromTree";

let app = Express.App.make();

let renderHTML = (_next, req, res) => {
  let helmetContext = Js.Obj.empty();
  let path = req |> Express.Request.path;
  let app =
    <ReactHelmet.Provider context=helmetContext>
      <ReasonApollo.Provider client=Apollo.client>
        <App initialUrl=path />
      </ReasonApollo.Provider>
    </ReactHelmet.Provider>;
  getDataFromTree(app)
  |> Js.Promise.then_(() =>
       {
         let title = helmetContext##helmet##title##toString();
         let meta = helmetContext##helmet##meta##toString();
         let link = helmetContext##helmet##link##toString();
         let script = helmetContext##helmet##script##toString();
         let htmlAttr = helmetContext##helmet##htmlAttributes##toString();
         let content = ReactDOMServerRe.renderToString(app);
         Express.Response.sendString(
           Template.make(
             ~content,
             ~title,
             ~meta,
             ~link,
             ~script,
             ~htmlAttr,
             (),
           ),
           res,
         );
       }
       |> Js.Promise.resolve
     );
};

Express.Static.defaultOptions()
|> Express.Static.make("dist/public")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/");

Express.Static.defaultOptions()
|> Express.Static.make("public")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/");

renderHTML
|> Express.PromiseMiddleware.from
|> Express.App.get(app, ~path="*");

let onListen = exn => {
  let error = Js.Nullable.toOption(exn);
  switch (error) {
  | Some(err) =>
    Js.log(
      "Express listen error: "
      ++ Js.Option.getWithDefault("(no message)", Js.Exn.message(err)),
    )
  | None =>
    Js.log(" ...listening on port " ++ Js.Int.toString(Config.Env.port))
  };
};

Express.App.listen(app, ~port=Config.Env.port, ~onListen, ());