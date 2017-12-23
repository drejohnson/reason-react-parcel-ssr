open Express;

open ReactRouter;

let app = express();

App.useOnPath(
  app,
  ~path="/",
  Express.Static.make("dist/client", Express.Static.defaultOptions())
  |> Express.Static.asMiddleware
);

App.useOnPath(
  app,
  ~path="/",
  Express.Static.make("static", Express.Static.defaultOptions()) |> Express.Static.asMiddleware
);

App.get(
  app,
  ~path="/*",
  Middleware.from(
    (_req, res, _next) => {
      let context = Js.Json.object_(Js.Dict.empty());
      let location = Utils.geturl(_req);
      let html =
        ReactDOMServerRe.renderToString(
          <ServerRouter context location> (Root.make()) </ServerRouter>
        );
      let helmet = ReactHelmet.renderStatic();
      let helmetHtmlAttributes = helmet##htmlAttributes##toString();
      let helmetTitle = helmet##title##toString();
      let helmetMeta = helmet##meta##toString();
      let helmetLink = helmet##link##toString();
      let helmetScript = helmet##script##toString();
      let filePath = Node_path.resolve("./dist", "index.html");
      let index = Node.Fs.readFileAsUtf8Sync(filePath);
      let document =
        index
        |> Js.String.replace({j|<html>|j}, {j|<html ⚡ $(helmetHtmlAttributes)>|j})
        |> Js.String.replace(
             {j|<head>|j},
             {j|<head>
              $helmetTitle
              $helmetMeta
              $helmetLink
              $helmetScript
          |j}
           )
        |> Js.String.replace({j|<div id="root">|j}, {j|<div id="root">$html|j});
      Response.sendString(res, document)
    }
  )
);

[@bs.val] external processEnvPort : string = "process.env.PORT";

let port = int_of_string("5678" /* processEnvPort */);

let onListen = (exn) => {
  let error = Js.Nullable.to_opt(exn);
  switch error {
  | Some(err) =>
    Js.log(
      "Express listen error: "
      ++ Js.Option.getWithDefault("(nothing to report)", Js.Exn.message(err))
    )
  | None => Js.log("Server" ++ " is listening on port " ++ Js.Int.toString(port))
  }
};

App.listen(app, ~port, ~onListen, ());