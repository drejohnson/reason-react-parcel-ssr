module Status = {
  let make = (_req, res, _next) => Express.Response.sendString("works", res) |> Js.Promise.resolve;
};