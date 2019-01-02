type state = { waypointEntered: bool };

type action =
  | EnterWaypoint
  | Noop;

let component = ReasonReact.reducerComponent("WaypointGenerator");

let css = Css.css;
let tw = Css.tw;

let make = (~wayKey, children) => {
  ...component,
  initialState: () => { waypointEntered: false },
  reducer: (action, _state) =>
    switch (action) {
    | EnterWaypoint => {
      Js.log("entered waypoint");
      ReasonReact.Update({ waypointEntered: true });
    }
    | Noop => ReasonReact.NoUpdate
    },
  render: ({send, state}) =>
    <Waypoint
      wayKey
      onEnter=((_) => send(state.waypointEntered ? Noop : EnterWaypoint))
    >
      {children(~waypointEntered=state.waypointEntered)}
    </Waypoint>
};