import { useState } from "react";

function App() {
  const [contador, setContador] = useState<number>(0);

  return (
    <>
      <h1>Contador de clics: {contador}</h1>
      <button onClick={() => setContador(contador + 1)}>
        Aumentar +1
      </button>
    </>
  );
}

export default App; 