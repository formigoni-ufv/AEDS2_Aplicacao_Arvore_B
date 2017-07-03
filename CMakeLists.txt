cmake_minimum_required(VERSION 3.7)
project(AEDS2_Aplicacao_Arvore_B)

set(CMAKE_CXX_STANDARD 11)

set(B_Tree b_tree.c b_tree.h main.c registry/registries_generator.c registry/registries_generator.h registry/registry.h registry/registry.c statistic.c statistic.h graph/graph_generator.c graph/graph_generator.h registry/Fisher_Yates.c registry/Fisher_Yates.h)

add_executable(main ${B_Tree})