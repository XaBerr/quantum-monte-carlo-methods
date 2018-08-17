class Ising {
  public:
    Ising();
    ~Ising();
    void generateRandom();
    double getEnergy();
  private:
    int nodes[10];
};
