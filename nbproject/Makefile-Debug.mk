#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/exportacao/exportacao.o \
	${OBJECTDIR}/gestao_dados/acomodacao/acomodacao.o \
	${OBJECTDIR}/gestao_dados/categoria_acomodacao/categoria_acomodacao.o \
	${OBJECTDIR}/gestao_dados/controle_arquivos/controle_arquivos.o \
	${OBJECTDIR}/gestao_dados/fornecedor/fornecedor.o \
	${OBJECTDIR}/gestao_dados/hospede/hospede.o \
	${OBJECTDIR}/gestao_dados/hotel/hotel.o \
	${OBJECTDIR}/gestao_dados/operador/operador.o \
	${OBJECTDIR}/gestao_dados/produto/produto.o \
	${OBJECTDIR}/importacao/importacao.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/relatorio/acomodacoes/listagemAcomodacao.o \
	${OBJECTDIR}/relatorio/hospedes/listagemHospede.o \
	${OBJECTDIR}/relatorio/produtosConsumo/listagemProdutosConsumo.o \
	${OBJECTDIR}/relatorio/produtosEstoque/listagemProdutosEstoqueMin.o \
	${OBJECTDIR}/relatorio/reservas/listagemReserva.o \
	${OBJECTDIR}/reserva/reserva.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hotel-project.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hotel-project.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hotel-project ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/exportacao/exportacao.o: exportacao/exportacao.c
	${MKDIR} -p ${OBJECTDIR}/exportacao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exportacao/exportacao.o exportacao/exportacao.c

${OBJECTDIR}/gestao_dados/acomodacao/acomodacao.o: gestao_dados/acomodacao/acomodacao.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/acomodacao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/acomodacao/acomodacao.o gestao_dados/acomodacao/acomodacao.c

${OBJECTDIR}/gestao_dados/categoria_acomodacao/categoria_acomodacao.o: gestao_dados/categoria_acomodacao/categoria_acomodacao.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/categoria_acomodacao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/categoria_acomodacao/categoria_acomodacao.o gestao_dados/categoria_acomodacao/categoria_acomodacao.c

${OBJECTDIR}/gestao_dados/controle_arquivos/controle_arquivos.o: gestao_dados/controle_arquivos/controle_arquivos.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/controle_arquivos
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/controle_arquivos/controle_arquivos.o gestao_dados/controle_arquivos/controle_arquivos.c

${OBJECTDIR}/gestao_dados/fornecedor/fornecedor.o: gestao_dados/fornecedor/fornecedor.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/fornecedor
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/fornecedor/fornecedor.o gestao_dados/fornecedor/fornecedor.c

${OBJECTDIR}/gestao_dados/hospede/hospede.o: gestao_dados/hospede/hospede.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/hospede
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/hospede/hospede.o gestao_dados/hospede/hospede.c

${OBJECTDIR}/gestao_dados/hotel/hotel.o: gestao_dados/hotel/hotel.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/hotel
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/hotel/hotel.o gestao_dados/hotel/hotel.c

${OBJECTDIR}/gestao_dados/operador/operador.o: gestao_dados/operador/operador.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/operador
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/operador/operador.o gestao_dados/operador/operador.c

${OBJECTDIR}/gestao_dados/produto/produto.o: gestao_dados/produto/produto.c
	${MKDIR} -p ${OBJECTDIR}/gestao_dados/produto
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gestao_dados/produto/produto.o gestao_dados/produto/produto.c

${OBJECTDIR}/importacao/importacao.o: importacao/importacao.c
	${MKDIR} -p ${OBJECTDIR}/importacao
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/importacao/importacao.o importacao/importacao.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/relatorio/acomodacoes/listagemAcomodacao.o: relatorio/acomodacoes/listagemAcomodacao.c
	${MKDIR} -p ${OBJECTDIR}/relatorio/acomodacoes
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/relatorio/acomodacoes/listagemAcomodacao.o relatorio/acomodacoes/listagemAcomodacao.c

${OBJECTDIR}/relatorio/hospedes/listagemHospede.o: relatorio/hospedes/listagemHospede.c
	${MKDIR} -p ${OBJECTDIR}/relatorio/hospedes
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/relatorio/hospedes/listagemHospede.o relatorio/hospedes/listagemHospede.c

${OBJECTDIR}/relatorio/produtosConsumo/listagemProdutosConsumo.o: relatorio/produtosConsumo/listagemProdutosConsumo.c
	${MKDIR} -p ${OBJECTDIR}/relatorio/produtosConsumo
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/relatorio/produtosConsumo/listagemProdutosConsumo.o relatorio/produtosConsumo/listagemProdutosConsumo.c

${OBJECTDIR}/relatorio/produtosEstoque/listagemProdutosEstoqueMin.o: relatorio/produtosEstoque/listagemProdutosEstoqueMin.c
	${MKDIR} -p ${OBJECTDIR}/relatorio/produtosEstoque
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/relatorio/produtosEstoque/listagemProdutosEstoqueMin.o relatorio/produtosEstoque/listagemProdutosEstoqueMin.c

${OBJECTDIR}/relatorio/reservas/listagemReserva.o: relatorio/reservas/listagemReserva.c
	${MKDIR} -p ${OBJECTDIR}/relatorio/reservas
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/relatorio/reservas/listagemReserva.o relatorio/reservas/listagemReserva.c

${OBJECTDIR}/reserva/reserva.o: reserva/reserva.c
	${MKDIR} -p ${OBJECTDIR}/reserva
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/reserva/reserva.o reserva/reserva.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
