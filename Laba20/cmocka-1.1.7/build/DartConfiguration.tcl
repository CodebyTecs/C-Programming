# This file is configured by CMake automatically as DartConfiguration.tcl
# If you choose not to use CMake, this file may be hand configured, by
# filling in the required variables.


# Configuration directories and files
SourceDirectory: /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7
BuildDirectory: /Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7/build

# Where to place the cost data store
CostDataFile: 

# Site is something like machine.domain, i.e. pragmatic.crd
Site: MacBook-Air-Tecs.local

# Build name is osname-revision-compiler, i.e. Linux-2.4.2-2smp-c++
BuildName: Darwin-cc

# Subprojects
LabelsForSubprojects: 

# Submission information
SubmitURL: https://test.cmocka.org/submit.php?project=cmocka
SubmitInactivityTimeout: 

# Dashboard start time
NightlyStartTime: 01:00:00 UTC

# Commands for the build/test/submit cycle
ConfigureCommand: "/opt/homebrew/bin/cmake" "/Users/tecs/Documents/Codding/Laba2_8/cmocka-1.1.7"
MakeCommand: /opt/homebrew/bin/cmake --build . --config "${CTEST_CONFIGURATION_TYPE}"
DefaultCTestConfigurationType: Release

# version control
UpdateVersionOnly: 

# CVS options
# Default is "-d -P -A"
CVSCommand: 
CVSUpdateOptions: 

# Subversion options
SVNCommand: 
SVNOptions: 
SVNUpdateOptions: 

# Git options
GITCommand: 
GITInitSubmodules: 
GITUpdateOptions: 
GITUpdateCustom: 

# Perforce options
P4Command: 
P4Client: 
P4Options: 
P4UpdateOptions: 
P4UpdateCustom: 

# Generic update command
UpdateCommand: 
UpdateOptions: 
UpdateType: true

# Compiler info
Compiler: 
CompilerVersion: 

# Dynamic analysis (MemCheck)
PurifyCommand: 
ValgrindCommand: 
ValgrindCommandOptions: 
DrMemoryCommand: 
DrMemoryCommandOptions: 
CudaSanitizerCommand: 
CudaSanitizerCommandOptions: 
MemoryCheckType: 
MemoryCheckSanitizerOptions: 
MemoryCheckCommand: MEMORYCHECK_COMMAND-NOTFOUND
MemoryCheckCommandOptions: 
MemoryCheckSuppressionFile: 

# Coverage
CoverageCommand: /usr/bin/gcov
CoverageExtraFlags: -l

# Testing options
# TimeOut is the amount of time in seconds to wait for processes
# to complete during testing.  After TimeOut seconds, the
# process will be summarily terminated.
# Currently set to 25 minutes
TimeOut: 1500

# During parallel testing CTest will not start a new test if doing
# so would cause the system load to exceed this value.
TestLoad: 

TLSVerify: 
TLSVersion: 

UseLaunchers: 
CurlOptions: 
# warning, if you add new options here that have to do with submit,
# you have to update cmCTestSubmitCommand.cxx

# For CTest submissions that timeout, these options
# specify behavior for retrying the submission
CTestSubmitRetryDelay: 5
CTestSubmitRetryCount: 3
