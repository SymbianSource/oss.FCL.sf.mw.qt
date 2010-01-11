@REM Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
@REM All rights reserved.

@ECHO OFF
SETLOCAL

SET __PRG__=%~dp0qt\rcc.exe

IF DEFINED QMAKESPEC GOTO :mkspec_set
SET QMAKESPEC=%~dp0qt\mkspecs\symbian-abld

:mkspec_set
"%__PRG__%" %*
