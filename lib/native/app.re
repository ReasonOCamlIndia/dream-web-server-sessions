let useState = a => {
  let (value, setValue) = React.useState(_ => a);
  let setValueStatic = value => setValue(_ => value);
  (value, setValueStatic);
};

[@react.component]
let make = () => {
  let (count, setCount) = useState(0);
  <div>
    <p>
      {React.string(" clicked " ++ Int.to_string(count) ++ " times")}
    </p>
    <button onClick={_ => setCount(count + 1)}>
      {React.string("Click me")}
    </button>
  </div>;
};
