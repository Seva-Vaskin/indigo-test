#include "IndigoSession.h"
#include "IndigoMolecule.h"
#include <string>

int main() {
    std::string smiles = "C";
    indigo_cpp::IndigoSessionPtr session = indigo_cpp::IndigoSession::create();
    auto molecule = session->loadMolecule(smiles);
    return 0;
}