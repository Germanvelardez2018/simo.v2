# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ggvelardez/tesis/repo-simo-version2/extras

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ggvelardez/tesis/repo-simo-version2/extras/build

# Include any dependencies generated for this target.
include CMakeFiles/simo-extras.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simo-extras.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simo-extras.dir/flags.make

CMakeFiles/simo-extras.dir/Core/src/main.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/Core/src/main.c.obj: ../Core/src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simo-extras.dir/Core/src/main.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/Core/src/main.c.obj   -c /home/ggvelardez/tesis/repo-simo-version2/extras/Core/src/main.c

CMakeFiles/simo-extras.dir/Core/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/Core/src/main.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/tesis/repo-simo-version2/extras/Core/src/main.c > CMakeFiles/simo-extras.dir/Core/src/main.c.i

CMakeFiles/simo-extras.dir/Core/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/Core/src/main.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/tesis/repo-simo-version2/extras/Core/src/main.c -o CMakeFiles/simo-extras.dir/Core/src/main.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj: /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj: /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building ASM object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj"
	/usr/bin/arm-none-eabi-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj   -c /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj: /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj: /home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj: /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj: /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj: /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.s

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj: CMakeFiles/simo-extras.dir/flags.make
CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj: /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj   -c /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.i"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c > CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.i

CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.s"
	/usr/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c -o CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.s

# Object files for target simo-extras
simo__extras_OBJECTS = \
"CMakeFiles/simo-extras.dir/Core/src/main.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj" \
"CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj"

# External object files for target simo-extras
simo__extras_EXTERNAL_OBJECTS =

simo-extras.elf: CMakeFiles/simo-extras.dir/Core/src/main.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_claim/claim.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/pico_platform/platform.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_sync/sync.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/sem.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/lock_core.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/time.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_time/timeout_helper.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_timer/timer.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/datetime.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/pheap.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_util/queue.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/mutex.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/common/pico_sync/critical_section.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/home/ggvelardez/pico/pico-sdk/src/rp2_common/hardware_gpio/gpio.c.obj
simo-extras.elf: CMakeFiles/simo-extras.dir/build.make
simo-extras.elf: CMakeFiles/simo-extras.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking C executable simo-extras.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simo-extras.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/arm-none-eabi-objcopy -Oihex simo-extras.elf simo-extras.hex
	/usr/bin/arm-none-eabi-objcopy -Obinary simo-extras.elf simo-extras.bin
	/usr/bin/arm-none-eabi-objdump -h simo-extras.elf >simo-extras.dis
	/usr/bin/arm-none-eabi-objdump -d simo-extras.elf >>simo-extras.dis
	elf2uf2/elf2uf2 simo-extras.elf simo-extras.uf2

# Rule to build all files generated by this target.
CMakeFiles/simo-extras.dir/build: simo-extras.elf

.PHONY : CMakeFiles/simo-extras.dir/build

CMakeFiles/simo-extras.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simo-extras.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simo-extras.dir/clean

CMakeFiles/simo-extras.dir/depend:
	cd /home/ggvelardez/tesis/repo-simo-version2/extras/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ggvelardez/tesis/repo-simo-version2/extras /home/ggvelardez/tesis/repo-simo-version2/extras /home/ggvelardez/tesis/repo-simo-version2/extras/build /home/ggvelardez/tesis/repo-simo-version2/extras/build /home/ggvelardez/tesis/repo-simo-version2/extras/build/CMakeFiles/simo-extras.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simo-extras.dir/depend

