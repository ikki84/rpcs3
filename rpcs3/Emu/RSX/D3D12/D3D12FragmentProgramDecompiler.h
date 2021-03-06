#pragma once

#include "Emu/RSX/RSXFragmentProgram.h"
#include <sstream>

#include "../Common/FragmentProgramDecompiler.h"

class D3D12FragmentDecompiler : public FragmentProgramDecompiler
{
protected:
	virtual std::string getFloatTypeName(size_t elementCount) override;
	virtual std::string getHalfTypeName(size_t elementCount) override;
	virtual std::string getFunction(enum FUNCTION) override;
	virtual std::string compareFunction(enum COMPARE, const std::string &, const std::string &) override;

	virtual void insertHeader(std::stringstream &OS) override;
	virtual void insertInputs(std::stringstream &OS) override;
	virtual void insertOutputs(std::stringstream &OS) override;
	virtual void insertConstants(std::stringstream &OS) override;
	virtual void insertGlobalFunctions(std::stringstream &OS) override;
	virtual void insertMainStart(std::stringstream &OS) override;
	virtual void insertMainEnd(std::stringstream &OS) override;
public:
	D3D12FragmentDecompiler(const RSXFragmentProgram &prog, u32& size);
};
