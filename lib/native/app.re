let useState = a => {
  let (value, setValue) = React.useState(_ => a);
  let setValueStatic = value => setValue(_ => value);
  (value, setValueStatic);
};


module Container = [%styled.section {|
  height: 100%;
  width: 100%;
  display: flex;
  align-items: center;
  justify-content: center;
|}];


[@react.component]
let make = () => {
  let (count, setCount) = useState(0);
  <Container>
    <section className="centered">
      <section>
        {React.string(" clicked " ++ Int.to_string(count) ++ " times")}
      </section>
      <button onClick={_ => setCount(count + 1)}>
        {React.string("Click me")}
      </button>
    </section>
  </Container>;
};
