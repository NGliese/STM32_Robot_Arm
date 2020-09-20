##############################################################################
#
#  Sample Makefile for C++ applications
#    Works for single and multiple file programs.
#    written by Robert Duvall
#    modified by Owen Astrachan
#    and by Garrett Mitchener
# 
##############################################################################

##############################################################################
# Application-specific variables
# EXEC is the name of the executable file
# SRC_FILES is a list of all source code files that must be linked
#           to create the executable
##############################################################################

export COMPONENTS_DIR=../Core/components
EXEC      = CPPUTEST
SRC_FILES = test_main.cpp
COMP_FILES= ./test_go/start_test/start_test.cpp \
			./test_go/gpio/gpio_test.cpp \
			./test_go/pwm_driver/pwm_driver_test.cpp \
			./test_go/pwm_driver/hal_test.cpp \
			./test_go/motor_controller/robot_bender_test.cpp \
			./test_go/overallsys/sys1_test.cpp \
			./test_go/sensor/test_current_sensor.cpp \
			./test_go/rtos/task_test.cpp \
			./test_go/task/Task_Current_Sensor_Test.cpp\
			./test_go/logging/logging_test.cpp\
			./test_go/timeservice/timeservice_test.cpp\
			./test_go/sensor/test_current_sensor_HAL.cpp\
			$(COMPONENTS_DIR)/Logging/Logger.cpp \
			$(COMPONENTS_DIR)/Communication_Protocol/i2c.cpp \
			$(COMPONENTS_DIR)/Communication_Protocol/uart.cpp \
			$(COMPONENTS_DIR)/GPIO/GPIO.cpp \
			$(COMPONENTS_DIR)/GPIO/HAL.cpp \
			$(COMPONENTS_DIR)/PWM_Driver/HAL.cpp \
			$(COMPONENTS_DIR)/PWM_Driver/PWM_Driver.cpp \
			$(COMPONENTS_DIR)/template/Basic_Controller.cpp \
			$(COMPONENTS_DIR)/template/Basic_Sensor.cpp \
			$(COMPONENTS_DIR)/Bender_Controller/Bender_Controller.cpp \
			$(COMPONENTS_DIR)/Current_Sensor/Current_Sensor.cpp \
			$(COMPONENTS_DIR)/Current_Sensor/HAL.cpp \
			$(COMPONENTS_DIR)/Step_Motor/Step_Motor.cpp \
			$(COMPONENTS_DIR)/Step_Motor/HAL.cpp \
			$(COMPONENTS_DIR)/Step_Motor_Controller/Step_Motor_Controller.cpp \
			$(COMPONENTS_DIR)/OverAllSystem/Single_Step_Motor_Control.cpp \
			$(COMPONENTS_DIR)/RTOS/Task.cpp \
			$(COMPONENTS_DIR)/RTOS/Task_Test.cpp \
			$(COMPONENTS_DIR)/Sensor_Thread/Mains_Current_Sensor_Task.cpp \
			$(COMPONENTS_DIR)/Timeservice/Timeservice.cpp \
			$(COMPONENTS_DIR)/Timeservice/RTC_HAL.cpp \
			
			


#
	    

#SRC_FILES = application.cc displaycommand.cc filelister.cc menu.cc \
#        menuitem.cc pixmap.cc quitcommand.cc readcommand.cc \
#        usepix.cc


##############################################################################
# Where to find course related files
# COURSE_DIR is where various header files (.h) and library files (.so and .a)
# are found.  LIB_DIR is where other libraries not specific to the course
# are kept.

# for CS machines
# COURSE_DIR = /usr/project/courses/cps108/lib
# LIB_DIR     = /usr/local/lib


export CPPUTEST_HOME=/usr
CPPFLAGS += -I$(CPPUTEST_HOME)/include 
# for acpub machines
COURSE_DIR = -I./test_go/ \
		-I$(CPPUTEST_HOME)/include  \
		-I$(COMPONENTS_DIR)/Communication_Protocol/include \
		-I$(COMPONENTS_DIR)/BPS/include \
		-I$(COMPONENTS_DIR)/GPIO/include \
		-I$(COMPONENTS_DIR)/PWM_Driver/include \
		-I$(COMPONENTS_DIR)/template/include \
		-I$(COMPONENTS_DIR)/Step_Motor_Controller/include \
		-I$(COMPONENTS_DIR)/Step_Motor/include \
		-I$(COMPONENTS_DIR)/Current_Sensor/include \
		-I$(COMPONENTS_DIR)/Bender_Controller/include \
		-I$(COMPONENTS_DIR)/UNIT_TEST/include \
		-I$(COMPONENTS_DIR)/OverAllSystem/include\
		-I$(COMPONENTS_DIR)/RTOS/include \
		-I$(COMPONENTS_DIR)/Sensor_Thread/include \
		-I$(COMPONENTS_DIR)/Logging/include \
		-I$(COMPONENTS_DIR)/Timeservice/include \
	     #-I/usr/include/x86_64-linux-gnu/curl/ 
LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt
	    
	     

LIB_DIR     = /usr/include/ \
	    
##############################################################################
# Compiler specifications
# These match the variable names given in /usr/share/lib/make/make.rules
# so that make's generic rules work to compile our files.
# gmake prefers CXX and CXXFLAGS for c++ programs
##############################################################################
# Which compiler should be used
CXX = g++
CC = $(CXX)

# What flags should be passed to the compiler

DEBUG_LEVEL     = -g #-g default
EXTRA_CCFLAGS   = -Wall
CXXFLAGS        = $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)
CCFLAGS         = $(CXXFLAGS)

# What flags should be passed to the C pre-processor
#   In other words, where should we look for files to include - note,
#   you should never need to include compiler specific directories here
#   because each compiler already knows where to look for its system
#   files (unless you want to override the defaults)

CPPFLAGS        = -I. \
                  -I$(COURSE_DIR)

# What flags should be passed to the linker
#   In other words, where should we look for libraries to link with - note,
#   you should never need to include compiler specific directories here
#   because each compiler already knows where to look for its system files.

LDFLAGS         = -L. \
                  -L$(COURSE_DIR) \
                  -R $(LIB_DIR):$(COURSE_DIR)

# What libraries should be linked with.
# For example, -lm links with libm.so, the math library.
# If you make a library of your own, say, libscandir.a, you have to link it
# in by adding -lscandir here.
LDLIBS          =  -lCppUTest -lCppUTestExt

# All source files have associated object files.
# This line sets `OFILES' to have the same value as `SRC_FILES' but
# with all the .cc's changed into .o's.
O_FILES         = $(SRC_FILES:%.cpp=%.o)


###########################################################################
# Additional rules make should know about in order to compile our files
###########################################################################
# all is the default rule
all: $(EXEC)


# exec depends on the object files
# It is made automagically using the LDFLAGS and LOADLIBES variables.
# The .o files are made automagically using the CXXFLAGS variable.
$(EXEC): $(O_FILES)

# to use `makedepend', the target is `depend'
depend:
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) $(COMP_FILES) $(SRC_FILES) -o $(EXEC) $(LD_LIBRARIES)
	#makedepend -- $(CXXFLAGS) -- -Y $(SRC_FILES)

# clean up after you're done
clean:
	$(RM) $(O_FILES) core *.rpo

very-clean: clean
	$(RM) $(EXEC)
