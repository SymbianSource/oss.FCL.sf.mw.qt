@REM Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
@REM All rights reserved.

@ECHO OFF
SETLOCAL

SET __PRG__=%~dp0qt\uic.exe

IF DEFINED QMAKESPEC GOTO :mkspec_set
SET QMAKESPEC=%~dp0qt\mkspecs\symbian-sbsv2

:mkspec_set
"%__PRG__%" %*
