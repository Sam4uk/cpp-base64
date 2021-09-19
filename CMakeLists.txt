cmake_minimum_required(VERSION 3.0)

project(base64
        VERSION 1.0.0
        DESCRIPTION "Base64 encoding and decoding with c++"
        HOMEPAGE_URL "https://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp"
        LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)

add_compile_options(
#    -Werror                 
   -Wall                   
   -Wextra                 
   -pedantic               
   -Wcast-align            
   -Wcast-qual             
   -Wctor-dtor-privacy     
   -Wdisabled-optimization 
   -Wformat=2              
   -Winit-self             
   -Wmissing-include-dirs  
   -Wmissing-declarations  
   -Wold-style-cast        
   -Woverloaded-virtual    
   -Wredundant-decls       
   -Wshadow                
   -Wsign-promo            
   -Wstrict-overflow=5     
   -Wundef                 
   -Wno-unused             
   -Wno-variadic-macros    
   -Wno-parentheses        
   -fdiagnostics-show-option
   )
   
set(G_TEST "${PROJECT_NAME}-google-test")
set(S_TEST "${PROJECT_NAME}-test")

enable_testing()

find_package(GTest REQUIRED)
   
set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(
    ${S_TEST} 
    test.cpp
    base64.cpp
    )
   
if( GTest_FOUND)
    
    file(GLOB G_TEST_SOURCES
        test-google*.cpp
    )  

    include_directories( ${GTEST_INCLUDE_DIRS})
    add_executable(
        ${G_TEST}
        ${G_TEST_SOURCES}
        base64.cpp
    )

    target_link_libraries(
        ${G_TEST} 
        ${GTEST_LIBRARIES}
        ${GTEST_MAIN_LIBRARIES}
        pthread
        )
    add_test(
        NAME ${G_TEST}
        COMMAND ${G_TEST}
    )
endif()

add_test(
    NAME ${S_TEST}
    COMMAND ${S_TEST}
)
