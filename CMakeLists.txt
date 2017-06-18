cmake_minimum_required(VERSION 3.7)
project(AEDS2_Aplicacao_Arvore_B)

set(CMAKE_CXX_STANDARD 11)

set(B_Tree b_tree.c b_tree.h main.c registries_generator.c registries_generator.h registry.h registry.c)

add_executable(tree ${B_Tree})