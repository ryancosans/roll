
// type state = {commandLog: string, currentCommand: string};

// let initState ={commandLog: "", currentCommand: ""}

// type action =
//   | UpdateCommandLog
//   | UpdateCurrentCommand;

// let reducer = (state, action, command) => 
//   switch action {
//   | UpdateCommandLog => { commandLog: state.commandLog ++ command }
//   | UpdateCurrentCommand => { currentCommand: command }
//   };


Random.init(int_of_float(Js.Date.now()));
let roll = () => {
  Js.log(Random.int(10))
};

[@react.component]
let make = () => {
  let (currentCommand, setCurrentCommand) = React.useState(() => "");
  let (commands, updateCommands) = React.useState(() => [|"ready to receive commands"|]);

  // let commandLog = List.map((command) => <div>{React.string(command)</div>, commands);
  
  <main>
    // <button>
    //   {React.string("click it")}
    // </button>
    // <div>
    //   (ReasonReact.array(Array.of_list(commandLog))
    // </div>
    <ul>
      {commands 
        -> Belt.Array.map(command => <li> {React.string(command)} </li>)
        -> React.array
      }
    </ul>
    // <div>{currentCommand |> React.string}</div>
    <input 
      value={currentCommand}
      onChange={
        event => { 
          let value = ReactEvent.Form.target(event)##value;
          setCurrentCommand(_ => value) 
        }
      }
      onKeyDown={
        event => {
          let key = ReactEvent.Keyboard.which(event);
          if (key === 13) {
            updateCommands(_ => Array.append([|currentCommand|], commands));
            setCurrentCommand(_ => "");
          };
        }
      }
      >
    </input>
  </main>
};