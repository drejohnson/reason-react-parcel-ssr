let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <ReactHelmet>
        <title> (Utils.text("ReasonReact Starter")) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <Hello message="Hello from home component" />
      <Box _as="p"> (Utils.text("Testing 1, 2")) </Box>
    </div>
};