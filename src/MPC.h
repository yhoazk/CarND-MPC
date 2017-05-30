#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

class MPC {
 public:
  MPC();

  virtual ~MPC();

  vector<double> predicted_x;
  vector<double> predicted_y;

  Eigen::MatrixXd coord_transform(vector<double_t>& map_x,vector<double_t> map_y, double_t veh_x, double_t veh_y, double_t veh_th);

  const int N_STATES = 6; /* This variable holds the number of states to be tracked {x,y,psi,v,cte,espi} */
  // Solve the model given an initial state and polynomial coefficients.
  // Return the first actuatotions.
  vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
};

#endif /* MPC_H */
