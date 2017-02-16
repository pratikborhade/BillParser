##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Core
ConfigurationName      :=Debug
WorkspacePath          :=/home/prat/Documents/BillParser
ProjectPath            :=/home/prat/Documents/BillParser/Core
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=prat
Date                   :=14/02/17
CodeLitePath           :=/home/prat/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Core.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -fopenmp
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/local/include/ $(IncludeSwitch)/usr/include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)tesseract $(LibrarySwitch)opencv_core $(LibrarySwitch)opencv_imgproc $(LibrarySwitch)opencv_highgui $(LibrarySwitch)opencv_features2d $(LibrarySwitch)opencv_imgcodecs 
ArLibs                 :=  "tesseract" "opencv_core" "opencv_imgproc" "opencv_highgui" "opencv_features2d" "opencv_imgcodecs" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/ $(LibraryPathSwitch)/usr/local/lib/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/BillParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/CharUtils.cpp$(ObjectSuffix) $(IntermediateDirectory)/tesseractapi.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImageProcessor.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImageProcessingUtils.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImageLogger.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prat/Documents/BillParser/Core/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/BillParser.cpp$(ObjectSuffix): BillParser.cpp $(IntermediateDirectory)/BillParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prat/Documents/BillParser/Core/BillParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BillParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BillParser.cpp$(DependSuffix): BillParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BillParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BillParser.cpp$(DependSuffix) -MM BillParser.cpp

$(IntermediateDirectory)/BillParser.cpp$(PreprocessSuffix): BillParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BillParser.cpp$(PreprocessSuffix) BillParser.cpp

$(IntermediateDirectory)/CharUtils.cpp$(ObjectSuffix): CharUtils.cpp $(IntermediateDirectory)/CharUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prat/Documents/BillParser/Core/CharUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CharUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CharUtils.cpp$(DependSuffix): CharUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CharUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CharUtils.cpp$(DependSuffix) -MM CharUtils.cpp

$(IntermediateDirectory)/CharUtils.cpp$(PreprocessSuffix): CharUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CharUtils.cpp$(PreprocessSuffix) CharUtils.cpp

$(IntermediateDirectory)/tesseractapi.cpp$(ObjectSuffix): tesseractapi.cpp $(IntermediateDirectory)/tesseractapi.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prat/Documents/BillParser/Core/tesseractapi.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tesseractapi.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tesseractapi.cpp$(DependSuffix): tesseractapi.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tesseractapi.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tesseractapi.cpp$(DependSuffix) -MM tesseractapi.cpp

$(IntermediateDirectory)/tesseractapi.cpp$(PreprocessSuffix): tesseractapi.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tesseractapi.cpp$(PreprocessSuffix) tesseractapi.cpp

$(IntermediateDirectory)/ImageProcessor.cpp$(ObjectSuffix): ImageProcessor.cpp $(IntermediateDirectory)/ImageProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prat/Documents/BillParser/Core/ImageProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageProcessor.cpp$(DependSuffix): ImageProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ImageProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ImageProcessor.cpp$(DependSuffix) -MM ImageProcessor.cpp

$(IntermediateDirectory)/ImageProcessor.cpp$(PreprocessSuffix): ImageProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageProcessor.cpp$(PreprocessSuffix) ImageProcessor.cpp

$(IntermediateDirectory)/ImageProcessingUtils.cpp$(ObjectSuffix): ImageProcessingUtils.cpp $(IntermediateDirectory)/ImageProcessingUtils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prat/Documents/BillParser/Core/ImageProcessingUtils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageProcessingUtils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageProcessingUtils.cpp$(DependSuffix): ImageProcessingUtils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ImageProcessingUtils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ImageProcessingUtils.cpp$(DependSuffix) -MM ImageProcessingUtils.cpp

$(IntermediateDirectory)/ImageProcessingUtils.cpp$(PreprocessSuffix): ImageProcessingUtils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageProcessingUtils.cpp$(PreprocessSuffix) ImageProcessingUtils.cpp

$(IntermediateDirectory)/ImageLogger.cpp$(ObjectSuffix): ImageLogger.cpp $(IntermediateDirectory)/ImageLogger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/prat/Documents/BillParser/Core/ImageLogger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageLogger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageLogger.cpp$(DependSuffix): ImageLogger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ImageLogger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ImageLogger.cpp$(DependSuffix) -MM ImageLogger.cpp

$(IntermediateDirectory)/ImageLogger.cpp$(PreprocessSuffix): ImageLogger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageLogger.cpp$(PreprocessSuffix) ImageLogger.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


