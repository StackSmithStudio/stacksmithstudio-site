let component = ReasonReact.statelessComponent("Modal");

let css = Css.css;
let tw = Css.tw;

let modalOverlayClass = [%bs.raw
  {| css(tw`
  fixed
  h-screen
  w-screen
  bg-grey-darkest
  opacity-50
`)
|}
];

let modalOuterClass = [%bs.raw {| css(tw`
  fixed
  w-screen
  h-screen
  flex
  justify-center
  items-center
  pointer-events-none
  z-50
`)|}];

let modalInternalClass = [%bs.raw
  {| css(tw`
  w-2/3
  flex
  bg-white
  pointer-events-auto
`)
|}
];

let make =
    (
      ~modalSelect: option('a),
      ~modalContents: 'a => ReasonReact.reactElement,
      ~closeFn: unit => unit,
      children,
    ) => {
  ...component,
  render: _self =>
    <div>
      {
        switch (modalSelect) {
        | Some(select) =>
          <div>
            <div
              className=modalOverlayClass
              onClick=(_ => closeFn() |> ignore)
            />
            <div className=modalOuterClass>
              <div className=modalInternalClass>
                {select |> modalContents}
              </div>
            </div>
          </div>
        | _ => <div />
        }
      }
      {ReasonReact.createDomElement("div", ~props=Js.Obj.empty(), children)}
    </div>,
};