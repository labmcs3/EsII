#include "Vector3.h"
#include "OdeSolver.h"

void OdeSolver::SetMatPoint(MatPoint tmp){
  m_p.push_back(tmp);
}

vector<MatPoint> OdeSolver::GetMatPoints(){
  return m_p;
}

MatPoint OdeSolver::GetMatPoint(unsigned int i){
  return m_p[i];
}

unsigned int OdeSolver::N(){
  return m_p.size();
}

void OdeSolver::T(double t0){
  m_t=t0;
}

double OdeSolver::T(){
  return      m_t;
}

void OdeSolver::Step(double h){
  m_h = h;
}

double OdeSolver::Step(){
  return   m_h;
}


Vector3 OdeSolver::m_eqDiff(unsigned int i, double t, vector<MatPoint> p){
  //STEP 3 Calcolo dell'accelerazione dovuta a forze interne e forze esterne
  return Vector3();
}

//Da implementare a cura dello studente
void OdeSolver::Solve(){

  if (m_method=="Eulero"){
    vector<Vector3>  k1(m_p.size());
    vector<Vector3>  w1(m_p.size());
    for (unsigned int i=0;i<m_p.size();i++){
      k1[i] = m_h*m_p[i].V();
      w1[i] = m_h*m_eqDiff(i,m_t,m_p);
    }

    for (unsigned int i=0;i<m_p.size();i++){
      m_p[i].R(m_p[i].R() + k1[i]);
      m_p[i].V(m_p[i].V() + w1[i]);
    }

  } else if (m_method=="Rk2"){
    // STEP 5 implementare Runge Kutta al secondo ordine
  }
  m_t += m_h;

}

