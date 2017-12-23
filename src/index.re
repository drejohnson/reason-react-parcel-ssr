open ReactRouter;

[@bs.val] [@bs.module "react-dom"] external hydrate : (ReasonReact.reactElement, 'a) => unit =
  "hydrate";

[@bs.module "./utils/registerServiceWorker"] external registerServiceWorker : unit => unit =
  "default";

let rootId = Utils.getElementById(Utils.dom, "root");

let app = () => <BrowserRouter> (Root.make()) </BrowserRouter>;

let render = (component) =>
  Utils.isPROD ?
    hydrate(component(), rootId) : ReactDOMRe.renderToElementWithId(component(), "root");

render(app);

registerServiceWorker();