let component = ReasonReact.statelessComponent("NotFound");

let make = _children => {
  ...component,
  render: _self => <Fragment> <Hello message="Page not found" /> </Fragment>,
};
