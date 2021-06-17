#include "PdhSpinodalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
PdhSpinodalApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

PdhSpinodalApp::PdhSpinodalApp(InputParameters parameters) : MooseApp(parameters)
{
  PdhSpinodalApp::registerAll(_factory, _action_factory, _syntax);
}

PdhSpinodalApp::~PdhSpinodalApp() {}

void
PdhSpinodalApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"PdhSpinodalApp"});
  Registry::registerActionsTo(af, {"PdhSpinodalApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
PdhSpinodalApp::registerApps()
{
  registerApp(PdhSpinodalApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
PdhSpinodalApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PdhSpinodalApp::registerAll(f, af, s);
}
extern "C" void
PdhSpinodalApp__registerApps()
{
  PdhSpinodalApp::registerApps();
}
