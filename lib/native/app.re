let useState = a => {
  let (value, setValue) = React.useState(_ => a);
  let setValueStatic = value => setValue(_ => value);
  (value, setValueStatic);
};

module Container = [%styled.section
  (~blah) => {|
  height: 100%;
  width: 100%;
  display: $(blah);
  align-items: center;
  justify-content: center;
|}
];

[@react.component]
let make = () => {
  let hey = React.string("hey");
  let (count, setCount) = useState(0);
  <Container blah=`flex>
    <Link href="/hello">{React.string("to hello")}</Link>
    <section className="centered">
      <p>{switch(true) { | true => hey | false => React.string("false")}}</p>
      <section>
        {React.string(" clicked " ++ Int.to_string(count) ++ " times")}
      </section>
      <button onClick={_ => setCount(count + 1)}>
        {React.string("Click me")}
      </button>
    </section>
  </Container>;
};
