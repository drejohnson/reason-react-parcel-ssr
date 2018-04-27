let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self => <Fragment> <Hello message="Hello from home" /> </Fragment>,
};
