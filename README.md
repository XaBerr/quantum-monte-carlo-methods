<p align="center">
    <img src="https://user-images.githubusercontent.com/16030020/79965872-e164f800-848c-11ea-8dcb-e526b2eeaadb.png" alt="logo" width=150 height=150>
  <h3 align="center">QMC-methods</h3>
  <p align="center">
    In this repository there are various implementations of the Monte Carlo algorithm for the calculation of the minimum in an Ising model.
    <br>
    <strong>- Requirements -</strong>
    <br>
    <br>
    <img src="https://img.shields.io/static/v1?label=cpp&message=11&color=007bff">
    <img src="https://img.shields.io/static/v1?label=cmake&message=3.14&color=007bff">
    <img src="https://img.shields.io/static/v1?label=OS&message=Win&color=28a745">
    <img src="https://img.shields.io/static/v1?label=OS&message=Mac&color=28a745">
    <img src="https://img.shields.io/static/v1?label=OS&message=Linux&color=28a745">
  </p>
</p>
<br>

## Installation
- **Manual**

  Download this repository:
  ```sh
  git clone git@github.com:XaBerr/quantum-monte-carlo-methods.git
  ```
  and compile it running:
  ```sh
  rm build/ -rf;cmake -S . -B build;make -C build;
  ```

- **CMake module**

  Module data:
  ```java
  FetchContent_Declare(
    "QMC-methods"
    GIT_REPOSITORY https://github.com/XaBerr/quantum-monte-carlo-methods.git
    GIT_TAG        1.0.0
  )
  ```

## Inclusion
All include file are avaiable in the `include` directory.
You can include each library individually:
```cpp
#include <QMC-methods/SimulatedAnnealing.h>
#include <QMC-methods/SantoroTosattiMartonak.h>
#include <QMC-methods/SwendsenWang.h>
using namespace QMCm;
```
or using the single include:
```cpp
#include <QMC-methods.h>
using namespace QMCm;
```

## Usage

These are the algorithms implemented until now:

- [x] Simulated Annealing
- [x] SwendsenWang
- [x] SantoroTosattiMartonak
- [ ] RiegerKawashimaDiscrete
- [ ] RiegerKawashimaContinuous

#### Simulated Annealing

First you must generate your Ising model.
```cpp
SimulatedAnnealing sa;
sa.startingConfig.size = 3;
sa.startingConfig.generate();
```

Then you can set the spin and fields values.

```cpp
/*
Initial nodes matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < sa.startingConfig.nodes.size(); i++) {
  for (int j = 0; j < sa.startingConfig.nodes.size())
    ; j++) {
    sa.startingConfig.nodes[i][j].value = 1;
    sa.startingConfig.nodes[i][j].spin = (uniform() < 0.5) ? 1 : -1;
  }
}

/*
Initial arcs matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < sa.startingConfig.arcs.size(); i++)
    for (int j = 0; j < sa.startingConfig.arcs[i].size(); j++)
      for (int k = 0; k < sa.startingConfig.arcs[i][k].size(); k++)
        sa.startingConfig.arcs[i][j][k].value = 1;
```

Last you run the algorithm few times.

```cpp
printf("The starting energy is [%f]\n", sa.startingConfig.getEnergy());
for (int i = 0; i < 10; i++) {
  sa.run();
  printf("The ending energy is [%f]\n", sa.endingConfig.getEnergy());
}
```

#### Swendsen Wang

First you must generate your Ising model.
```cpp
SwendsenWang sw;
sw.startingConfig.size = 3;
sw.startingConfig.generate();
```

Then you can set the spin and fields values.

```cpp
/*
Initial nodes matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < sw.startingConfig.nodes.size(); i++) {
  for (int j = 0; j < sw.startingConfig.nodes.size())
    ; j++) {
    sw.startingConfig.nodes[i][j].value = 1;
    sw.startingConfig.nodes[i][j].spin = (uniform() < 0.5) ? 1 : -1;
  }
}

/*
Initial arcs matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < sw.startingConfig.arcs.size(); i++)
    for (int j = 0; j < sw.startingConfig.arcs[i].size(); j++)
      for (int k = 0; k < sw.startingConfig.arcs[i][k].size(); k++)
        sw.startingConfig.arcs[i][j][k].value = 1;
```

Last you run the algorithm few times.

```cpp
printf("The starting energy is [%f]\n", sw.startingConfig.getEnergy());
for (int i = 0; i < 10; i++) {
  sw.run();
  printf("The ending energy is [%f]\n", sw.endingConfig.getEnergy());
}
```

#### Santoro Tosatti Martonak

First you must generate your Ising model that will be used to generate the transverse once.
```cpp
SantoroTosattiMartonak stm;
stm.startingConfig.numberOfreplicas = 3;
stm.startingConfig.mainReplica.size = 3;
stm.startingConfig.mainReplica.generate();
```

Then you can set the spin and fields values.

```cpp
/*
Initial nodes matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < stm.startingConfig.mainReplica.nodes.size(); i++) {
  for (int j = 0; j < stm.startingConfig.mainReplica.nodes[i].size(); j++) {
    stm.startingConfig.mainReplica.nodes[i][j].value = 1;
    stm.startingConfig.mainReplica.nodes[i][j].spin =
        (uniform() < 0.5) ? 1 : -1;
  }
}

/*
Initial arcs matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < stm.startingConfig.mainReplica.arcs.size(); i++)
  for (int j = 0; j < stm.startingConfig.mainReplica.arcs[i].size(); j++)
    for (int k = 0; k < stm.startingConfig.mainReplica.arcs[i][j].size(); k++)
      stm.startingConfig.mainReplica.arcs[i][j][k].value = 1;
```

Here we have an intermediate step to generate the transverse Ising model.

```cpp
stm.startingConfig.generate();
```

Last you run the algorithm few times.

```cpp
printf("The starting energy is [%f]\n", stm.startingConfig.getIsingDiscreteEnergy());
for (int i = 0; i < 10; i++) {
  stm.run();
  printf("The ending energy is [%f]\n", stm.endingConfig.getIsingDiscreteEnergy());
}
```

## 2D Ising model parameters

Here we have the parameters and theirs default values.
```cpp
// the size of the square of the Ising model
size             = 3;

// energy configuration parameters
favorAlignment   = true;
favorSpinUp      = true;

// if we want the structure is recursive
periodicBoundary = false;

// this is the boundary of the random generation that is used by default
nodeMaxValue     = 1;
nodeMinValue     = -1;
arcMaxValue      = 1;
arcMinValue      = -1;
```


## 2D Transverse Ising model parameters

Because it has embedded the 2d Ising model, it have the same parameters described before.
This is the additional parameters and theirs default values.
```cpp
// number of replicas of the ising model
numberOfreplicas = 3;

// initial strength of the transverse field
tranverseField   = 1;

// periodic boundary along the time direction
periodicBoundary = false;
```

## Example
Also check out the example in `apps/example.cpp`.