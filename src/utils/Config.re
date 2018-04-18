[@bs.module "dotenv"] external config : {. "silent": bool} => unit = "config";

/* Load environment variables from a .env file if it exists */
config({"silent": true});

let getEnvVar = (key, fallback) =>
  Js.Option.getWithDefault(
    fallback,
    Js.Dict.get(Node.Process.process##env, key),
  );

module Env = {
  let isDev = getEnvVar("NODE_ENV", "production") === "development";
  let port = Utils.parseInt(getEnvVar("PORT", "1234"), 10);
  let googleAnalyticsId =
    Utils.parseInt(getEnvVar("GA_TRACKING_ID", "UA-XXXXXXXX-X"));
  let graphqlEndpoint = Utils.parseInt(getEnvVar("GRAPHQL_ENDPOINT", ""));
};