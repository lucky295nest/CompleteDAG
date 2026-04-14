# Návod na zprovoznění

naklonovat
```shell
git clone --depth=1 https://github.com/lucky295nest/CompleteDAG.git
```

vytvořit `build` složku a vlézt do ní
```shell
mkdir build
cd build
```

použít `cmake`
```shell
cmake ..
```

vytvořit executable
```shell
make
```

executable se vytvoří v build složce ve které se nacházíte\
použití je `./CompleteDAG vstupni_soubor.txt vystupni_soubor.txt`

>tady je příklad pro jeden z testů ve složce tests and outputs\
výstupní soubory jsou vyplněné předem takže je buď promazat\
nebo vytvořit jiný soubor. Výstupní soubor se sám nevytvoří a musí existovat předem
```shell
touch my-output.txt
./CompleteDAG ../tests-and-outputs/test-1.txt ./my-output.txt
```

---

vytvoření doxy
>doxygen musí být stažený
```shell
cd ..
doxygen Doxyfile
```
html dokumentace se vytvoří ve složce docs.
pro její otevření otevřete soubor `index.html` v prohlížeči
```shell
cd docs/html/
firefox index.html
```

---
#### zdroje
- https://w3schools.com
- https://en.cppreference.com/
- https://en.wikipedia.org/wiki/Topological_sorting