let component = ReasonReact.statelessComponent("Section");

let css = Css.css;
let cx = Css.cx;
let tw = Css.tw;

let titleInternalClass = 
  cx(
    [%bs.raw {| css(tw` text-lg `) |}],
  "text-primary-gold"
);

let sectionClass = cx(
  [%bs.raw {| css(tw`
    flex
    flex-wrap
    relative
  `) |} ],
  Utils.Css.cssToEmotionMediaQuery(Utils.Css.SM, "
    display: contents;
  ")
);

let centerContent = [%bs.raw {| css(tw`
  pt-12
`) |} ];

let splashClassInternal = [%bs.raw {| css(tw`
  sm:block
  absolute
  sm:static
  w-full
  h-full
  sm:w-auto
  sm:h-auto
`) |} ];

let textInternal = [%bs.raw {| css(tw`
  z-10
  px-8
  sm:px-0
  w-full
  sm:w-auto
  pb-12
  flex
  flex-col
  justify-between
`) |} ];

let imageInternal = [%bs.raw {| css(tw`
  z-10
  px-8
  sm:px-0
  w-full
  sm:w-auto
  pb-12
`) |} ];

let imageSrcClass = [%bs.raw {| css(tw`
  shadow-lg
  w-full
  h-auto
`) |} ];

let logoClass = [%bs.raw {| css(tw`
  h-12
  w-12
`) |} ];

let logoRightClass = [%bs.raw {| css(tw`
  flex
  justify-end
`) |} ];

type logoShow =
  | RIGHT
  | LEFT
  | NONE;

let make = (
  ~title,
  ~textClass="",
  ~titleClass="",
  ~image=None,
  ~imageClass="",
  ~splashClass,
  ~logoShow=NONE,
  ~rowClass,
children) => {
  ...component,
  render: _self =>
    <div className=sectionClass>
      <div className=cx(cx(splashClass, rowClass), splashClassInternal)/>
      <div className=cx(cx(cx(centerContent, rowClass), textClass), textInternal)>
        <div>
          <div className=titleInternalClass> {ReasonReact.string(title)} </div>
          {children |> ReasonReact.array}
        </div>
        {
          logoShow != NONE ?
            <div className=(logoShow == RIGHT ? logoRightClass : "")>
              <StackSmithStudioText text=false dark=true logoClass />
            </div> :
          <div/>
        }
        
      </div>
      {
        Belt.Option.mapWithDefault(image, <div />, (imageVal) =>
          <div className=cx(cx(cx(centerContent, rowClass), imageClass), imageInternal)>
            <img className=imageSrcClass src=imageVal />
          </div>
        )
      }
    </div>
};