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
All include files are available in the `include` directory.
After the inclusion it is required to instantiate the random distribution `Uniform`.
Libraries can be included individually:
```cpp
#include <QMC-methods/SimulatedAnnealing.h>
#include <QMC-methods/SantoroTosattiMartonak.h>
#include <QMC-methods/SwendsenWang.h>
using namespace QMCm;
static Uniform uniform;
```
or in batch using the single include:
```cpp
#include <QMC-methods.h>
using namespace QMCm;
static Uniform uniform;
```

## Usage

These are the algorithms implemented until now:

- [x] [Simulated Annealing](https://link.springer.com/chapter/10.1007/0-387-28356-0_7)
- [x] [SwendsenWang](https://journals.aps.org/prl/abstract/10.1103/PhysRevLett.58.86)
- [x] [SantoroTosattiMartonak](https://arxiv.org/abs/cond-mat/0205280)
- [ ] [RiegerKawashimaDiscrete](https://science.sciencemag.org/content/348/6231/215)
- [ ] [RiegerKawashimaContinuous](https://arxiv.org/abs/cond-mat/9802104)

#### Simulated Annealing

First you must generate your Ising model.
```cpp
SimulatedAnnealing monteCarlo;
monteCarlo.startingConfig.size = 3;
monteCarlo.startingConfig.generate();
```

Then you can set the spins and fields values.

```cpp
/*
Initial nodes matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < monteCarlo.startingConfig.nodes.size(); i++) {
  for (int j = 0; j < monteCarlo.startingConfig.nodes.size(); j++) {
    monteCarlo.startingConfig.nodes[i][j].value = 1;
    monteCarlo.startingConfig.nodes[i][j].spin = (uniform() < 0.5) ? 1 : -1;
  }
}

/*
Initial arcs matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < monteCarlo.startingConfig.arcs.size(); i++)
    for (int j = 0; j < monteCarlo.startingConfig.arcs[i].size(); j++)
      for (int k = 0; k < monteCarlo.startingConfig.arcs[i][k].size(); k++)
        monteCarlo.startingConfig.arcs[i][j][k].value = 1;
```

Last you run the algorithm few times.

```cpp
printf("The starting energy is [%f]\n", monteCarlo.startingConfig.getEnergy());
for (int i = 0; i < 10; i++) {
  monteCarlo.run();
  printf("The ending energy is [%f]\n", monteCarlo.endingConfig.getEnergy());
}
```

#### Swendsen Wang

First you must generate your Ising model.
```cpp
SwendsenWang monteCarlo;
monteCarlo.startingConfig.size = 3;
monteCarlo.startingConfig.generate();
```

Then you can set the spins and fields values.

```cpp
/*
Initial nodes matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < monteCarlo.startingConfig.nodes.size(); i++) {
  for (int j = 0; j < monteCarlo.startingConfig.nodes.size(); j++) {
    monteCarlo.startingConfig.nodes[i][j].value = 1;
    monteCarlo.startingConfig.nodes[i][j].spin = (uniform() < 0.5) ? 1 : -1;
  }
}

/*
Initial arcs matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < monteCarlo.startingConfig.arcs.size(); i++)
    for (int j = 0; j < monteCarlo.startingConfig.arcs[i].size(); j++)
      for (int k = 0; k < monteCarlo.startingConfig.arcs[i][k].size(); k++)
        monteCarlo.startingConfig.arcs[i][j][k].value = 1;
```

Last you run the algorithm few times.

```cpp
printf("The starting energy is [%f]\n", monteCarlo.startingConfig.getEnergy());
for (int i = 0; i < 10; i++) {
  monteCarlo.run();
  printf("The ending energy is [%f]\n", monteCarlo.endingConfig.getEnergy());
}
```

#### Santoro Tosatti Martonak

First you must generate your Ising model that will be used to generate the transverse once.
```cpp
SantoroTosattiMartonak transverseMonteCarlo;
transverseMonteCarlo.startingConfig.numberOfreplicas = 3;
transverseMonteCarlo.startingConfig.mainReplica.size = 3;
transverseMonteCarlo.startingConfig.mainReplica.generate();
```

Then you can set the spins and fields values.

```cpp
/*
Initial nodes matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < transverseMonteCarlo.startingConfig.mainReplica.nodes.size(); i++) {
  for (int j = 0; j < transverseMonteCarlo.startingConfig.mainReplica.nodes[i].size(); j++) {
    transverseMonteCarlo.startingConfig.mainReplica.nodes[i][j].value = 1;
    transverseMonteCarlo.startingConfig.mainReplica.nodes[i][j].spin =
        (uniform() < 0.5) ? 1 : -1;
  }
}

/*
Initial arcs matrix of values
1 1 1
1 1 1
1 1 1
*/
for (int i = 0; i < transverseMonteCarlo.startingConfig.mainReplica.arcs.size(); i++)
  for (int j = 0; j < transverseMonteCarlo.startingConfig.mainReplica.arcs[i].size(); j++)
    for (int k = 0; k < transverseMonteCarlo.startingConfig.mainReplica.arcs[i][j].size(); k++)
      transverseMonteCarlo.startingConfig.mainReplica.arcs[i][j][k].value = 1;
```

Here you have an intermediate step to generate the transverse Ising model.

```cpp
transverseMonteCarlo.startingConfig.generate();
```

Last you run the algorithm few times.

```cpp
printf("The starting energy is [%f]\n", transverseMonteCarlo.startingConfig.getIsingDiscreteEnergy());
for (int i = 0; i < 10; i++) {
  transverseMonteCarlo.run();
  printf("The ending energy is [%f]\n", transverseMonteCarlo.endingConfig.getIsingDiscreteEnergy());
}
```

## 2D Ising model parameters

The parameters for the Ising model (__monteCarlo.startingConfig__, __transverseMonteCarlo.startingConfig.mainReplica__) are the following:
```cpp
// the size of the square of the Ising model
monteCarlo.startingConfig.size             = +3;

// energy configuration parameters
monteCarlo.startingConfig.favorAlignment   = true;
monteCarlo.startingConfig.favorSpinUp      = true;

// if we want the structure is recursive
monteCarlo.startingConfig.periodicBoundary = false;

// this is the boundary of the random generation that is used by default
monteCarlo.startingConfig.nodeMaxValue     = +1;
monteCarlo.startingConfig.nodeMinValue     = -1;
monteCarlo.startingConfig.arcMaxValue      = +1;
monteCarlo.startingConfig.arcMinValue      = -1;
```


## 2D Transverse Ising model parameters

The parameters for the transverse Ising model (__transverseMonteCarlo.startingConfig__) are the following.
```cpp
// number of replicas of the Ising model
transverseMonteCarlo.startingConfig.numberOfreplicas = 3;

// initial strength of the transverse field
transverseMonteCarlo.startingConfig.transverseField   = 1;

// periodic boundary along the time direction
transverseMonteCarlo.startingConfig.periodicBoundary = false;
```

## Example
Also check out the example in `apps/example.cpp`.

## Contributions
At the moment I don't have time to finish the last two algorithms, if you want to finish and push them, I would gladly accept a pull request.

Of course if you like this repository remember to :star: the project!