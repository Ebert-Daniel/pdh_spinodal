//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "PdhSpinodalTestApp.h"
#include "PdhSpinodalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
PdhSpinodalTestApp::validParams()
{
  InputParameters params = PdhSpinodalApp::validParams();
  return params;
}

PdhSpinodalTestApp::PdhSpinodalTestApp(InputParameters parameters) : MooseApp(parameters)
{
  PdhSpinodalTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

PdhSpinodalTestApp::~PdhSpinodalTestApp() {}

void
PdhSpinodalTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  PdhSpinodalApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"PdhSpinodalTestApp"});
    Registry::registerActionsTo(af, {"PdhSpinodalTestApp"});
  }
}

void
PdhSpinodalTestApp::registerApps()
{
  registerApp(PdhSpinodalApp);
  registerApp(PdhSpinodalTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
PdhSpinodalTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PdhSpinodalTestApp::registerAll(f, af, s);
}
extern "C" void
PdhSpinodalTestApp__registerApps()
{
  PdhSpinodalTestApp::registerApps();
}
