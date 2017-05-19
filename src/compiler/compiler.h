#pragma once
#include "llvm.h"
#include "ast.h"
#include "runtime.h"

namespace rift {

class RiftModule;

class Compiler : public Visitor {
public:

    /** Returns the llvm's context for the compiler.
     */
    static llvm::LLVMContext & context() {
        static llvm::LLVMContext context;
        return context;
    }

    int compile(ast::Fun * f);

    Compiler();

    ~Compiler() {
        delete b;
    }


private:

    friend class JIT;

    llvm::Value * result;
    llvm::Value * env;

    unique_ptr<llvm::Module> m;
    llvm::Function * f;
    llvm::IRBuilder<>  * b;
};






}
