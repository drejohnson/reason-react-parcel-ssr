type dom;

type element;

[@bs.val] external dom : dom = "document";

[@bs.send] external getElementById : (dom, string) => element = "getElementById";

[@bs.scope ("window", "location")] [@bs.val] external pathname : string = "pathname";

[@bs.val] external nodeEnv : string = "process.env.NODE_ENV";

[@bs.val] external browserEnv : bool = "process.browser";

let isDEV = Js.Boolean.to_js_boolean(nodeEnv !== "production");

let isPROD = Js.Boolean.to_js_boolean(nodeEnv === "production");

let isBrowser = Js.Boolean.to_js_boolean(browserEnv);

let text = ReasonReact.stringToElement;

let dangerousHtml: string => Js.t('a) = (html) => {"__html": html};

[@bs.get_index] external gett : ('a, string) => Js.Json.t = "";

let geturl = (req) => gett(req, "url");