========================================================================
    DYNAMIC LINK LIBRARY : TibiaInj Project Overview
========================================================================

AppWizard has created this TibiaInj DLL for you.

This file contains a summary of what you will find in each of the files that
make up your TibiaInj application.


TibiaInj.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

TibiaInj.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Core.cpp
    This is the main DLL source file.

	core.cpp is instantiated directly from DllMain, and contains instances of each of 
	the additional classes available to it. That includes all information gathering and
	all control classes. It stores a pointer to each of these classes, allowing singular 
	instances to run, further to this each of the instantiated classes takes a parameter
	of type * Core (pointer to core class). Passing in the core class to these 
	constructors allows each individual class access to all public members of each 
	instantiated class we have. 

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named TibiaInj.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
