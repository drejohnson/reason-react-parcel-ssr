type renderFunc =
  {
    .
    "match": Js.Dict.t(string),
    "history": History.History.t,
    "location": History.History.Location.t
  } =>
  ReasonReact.reactElement;

module BrowserRouter = {
  [@bs.module "react-router-dom"] external browserRouter : ReasonReact.reactClass =
    "BrowserRouter";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=browserRouter, ~props=Js.Obj.empty(), children);
};

module ServerRouter = {
  [@bs.module "react-router-dom"] external staticRouter : ReasonReact.reactClass = "StaticRouter";
  let make = (~context: Js.Json.t, ~location: Js.Json.t, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=staticRouter,
      ~props={"context": context, "location": location},
      children
    );
};

module Route = {
  [@bs.module "react-router-dom"] external route : ReasonReact.reactClass = "Route";
  let make =
      (
        ~component: option(('a => ReasonReact.reactElement))=?,
        ~exact: bool=false,
        ~path: option(string)=?,
        ~render: option(renderFunc)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=route,
      ~props={
        "exact": Js.Boolean.to_js_boolean(exact),
        "path": Js.Nullable.from_opt(path),
        "component": Js.Nullable.from_opt(component),
        "render": Js.Nullable.from_opt(render)
      },
      children
    );
};

module Switch = {
  [@bs.module "react-router-dom"] external _switch : ReasonReact.reactClass = "Switch";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass=_switch, ~props=Js.Obj.empty(), children);
};

module Link = {
  [@bs.module "react-router-dom"] external link : ReasonReact.reactClass = "Link";
  let make = (~_to, children) =>
    ReasonReact.wrapJsForReason(~reactClass=link, ~props={"to": _to}, children);
};