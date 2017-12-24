type dom;

type element;

[@bs.val] external dom : dom = "document";

[@bs.send] external getElementById : (dom, string) => element = "getElementById";

[@bs.scope ("window", "location")] [@bs.val] external pathname : string = "pathname";

[@bs.val] external nodeEnv : string = "process.env.NODE_ENV";

[@bs.val] external browserEnv : bool = "process.browser";

[@bs.val] external requireAssetURI : string => string = "require";

let isDEV = nodeEnv !== "production";

let isPROD = nodeEnv === "production";

let isBrowser = browserEnv;

let text = ReasonReact.stringToElement;

let dangerousHtml: string => Js.t('a) = (html) => {"__html": html};

[@bs.get_index] external gett : ('a, string) => Js.Json.t = "";

let geturl = (req) => gett(req, "url");