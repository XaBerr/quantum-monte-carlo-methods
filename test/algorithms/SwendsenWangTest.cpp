#include "../../src/include.h"
#include "../catch.hpp"

static Uniform uniform;

void printJoins(std::vector<std::vector<std::vector<bool>>> joins);
void printIsing(Ising2d ising);

TEST_CASE("SwendsenWang SwendsenWang()", "[sw]") {
  SwendsenWang sw;
  REQUIRE(sw.scale != 0);
}

TEST_CASE("SwendsenWang [prob] generateJoins(ising)", "[sw, joins]") {
  SwendsenWang sw;
  Ising2d ising;
  int trueCount  = 0;
  int falseCount = 0;
  std::vector<std::vector<std::vector<bool>>> joins;
  ising.size = 10;
  ising.generate();
  joins = sw.generateJoins(ising);

  for (int i = 0; i < joins.size(); i++)
    for (int j = 0; j < joins[i].size(); j++)
      for (int k = 0; k < joins[i][j].size(); k++)
        if (joins[i][j][k])
          trueCount++;
        else
          falseCount++;

  REQUIRE(trueCount > 0);
  REQUIRE(falseCount > 0);
}

void printJoins(std::vector<std::vector<std::vector<bool>>> joins) {
  printf("-----------UP-----------\n");
  for (int i = 0; i < joins.size(); i++) {
    for (int j = 0; j < joins[i].size(); j++)
      printf(" %d", joins[i][j][UP] ? 1 : 0);
    printf("\n");
  }

  printf("----------LEFT----------\n");
  for (int i = 0; i < joins.size(); i++) {
    for (int j = 0; j < joins[i].size(); j++)
      printf(" %d", joins[i][j][LEFT] ? 1 : 0);
    printf("\n");
  }
}

void printIsing(Ising2d ising) {
  printf("----------NODES---------\n");
  for (int i = 0; i < ising.nodes.size(); i++) {
    for (int j = 0; j < ising.nodes[i].size(); j++)
      printf(" %d[%f]", ising.nodes[i][j].spin, ising.nodes[i][j].value);
    printf("\n");
  }

  printf("---------ARCS-UP-------\n");
  for (int i = 0; i < ising.arcs.size(); i++) {
    for (int j = 0; j < ising.arcs[i].size(); j++)
      printf(" %f[%s][%s]", ising.arcs[i][j][UP].value,
             ising.arcs[i][j][UP].node1 != nullptr ? ising.arcs[i][j][UP].node1->id.c_str() : "NULL",
             ising.arcs[i][j][UP].node2 != nullptr ? ising.arcs[i][j][UP].node2->id.c_str() : "NULL");
    printf("\n");
  }

  printf("--------ARCS-DOWN------\n");
  for (int i = 0; i < ising.arcs.size(); i++) {
    for (int j = 0; j < ising.arcs[i].size(); j++)
      printf(" %f[%s][%s]", ising.arcs[i][j][LEFT].value,
             ising.arcs[i][j][LEFT].node1 != nullptr ? ising.arcs[i][j][LEFT].node1->id.c_str() : "NULL",
             ising.arcs[i][j][LEFT].node2 != nullptr ? ising.arcs[i][j][LEFT].node2->id.c_str() : "NULL");
    printf("\n");
  }
}