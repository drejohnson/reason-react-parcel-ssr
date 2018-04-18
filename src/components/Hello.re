let component = ReasonReact.statelessComponent("Hello");

let make = (~message, _children) => {
  ...component,
  render: _self => <h1> (message |> Utils.text) </h1>,
};