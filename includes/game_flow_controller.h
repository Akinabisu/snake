#pragma once

#pragma once

class GameFlowController {
   public:
    virtual bool wantsToExit() = 0;
    virtual bool wantsToRestart() = 0;
};