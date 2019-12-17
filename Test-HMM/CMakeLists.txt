cmake_minimum_required(VERSION  2.8)
project(test_game_engine CXX)

set(HMMsrc "./src/")
add_library(
    HMM
    ${HMMsrc}/HMM.h
)

set(TESThelpersSrc "./tests/")
add_library(
    TestHelpers
    ${TESThelpersSrc}/test_helpers.h
)

enable_testing()
add_definitions(-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN -DHANDMADE_MATH_IMPLEMENTATION -DHANDMADE_MATH_CPP_MODE) 
set (BOOST_ROOT $ENV{boost_test})
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
set_target_properties(HMM PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(TestHelpers PROPERTIES LINKER_LANGUAGE CXX)

include_directories (${Boost_INCLUDE_DIRS} ${HMMsrc} ${TEST_HELPERS_DIR})


set(TESTS_SRCS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

file(GLOB TESTS_SRCS ${TESTS_SRCS_DIR}/*.cpp)
foreach(testSrc ${TESTS_SRCS})
    #Extract the filename without an extension (NAME_WE)
    get_filename_component(testName ${testSrc} NAME_WE)

    #Add compile target
    add_executable(${testName} ${testSrc})

    #link to Boost libraries AND your targets and dependencies
    target_link_libraries(${testName} ${TestHelpers} ${Boost_LIBRARIES} HMM)
    
    add_test(hmm_${testName} ${testName})
endforeach(testSrc)

