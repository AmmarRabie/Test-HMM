cmake_minimum_required(VERSION  2.8)
project(test_game_engine CXX)

set(HMMsrc "./")
add_library(
    HMM
    ${HMMsrc}/HMM.h
)
    
enable_testing()
add_definitions(-DBOOST_TEST_DYN_LINK) 
set (BOOST_ROOT $ENV{boost_test})
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS} ${HMMsrc})

set_target_properties(HMM PROPERTIES LINKER_LANGUAGE CXX)

set(TEST_SRCS "./tests/")

file(GLOB TEST_SRCS RELATIVE ${TEST_SRCS} *.cpp)

foreach(testSrc ${TEST_SRCS})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)

        #Add compile target
        add_executable(${testName} ${testSrc})

        #link to Boost libraries AND your targets and dependencies
        target_link_libraries(${testName} ${Boost_LIBRARIES} HMM)
        
        add_test(${testName} hmm_test)
endforeach(testSrc)

