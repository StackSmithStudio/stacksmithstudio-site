type queryString;
type gql = (. string) => queryString;

type dataWithQuery('a) = {. "data": 'a};

module Container = (Config: ReasonApolloTypes.Config) => {
  [@bs.module "gatsby"] external graphql: gql = "graphql";
  let query = graphql(. Config.query);
  type params = dataWithQuery(Config.t);
  type container = params => ReasonReact.reactElement;
};