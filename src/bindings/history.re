module History = {
  type t;
  [@bs.send] external goBack : t => unit = "";
  [@bs.send] external goForward : t => unit = "";
  [@bs.send] external go : (t, ~jumps: int) => unit = "";
  [@bs.get] external length : t => int = "";
  [@bs.get] external location : t => string = "";
  module Location = {
    type t;
    [@bs.get] external pathname : t => string = "";
    [@bs.get] external search : t => string = "";
    [@bs.get] external hash : t => string = "";
  };
};