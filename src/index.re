open ReactRouter;

[@bs.module "./utils/registerServiceWorker"] external registerServiceWorker : unit => unit =
  "default";

ReactDOMRe.renderToElementWithId(<BrowserRouter> (Root.make()) </BrowserRouter>, "root");

registerServiceWorker();