let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment> <Hello message="Hello from about component" /> </Fragment>,
};
