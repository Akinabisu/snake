#pragma once

class GameFlowController {
   protected:
    bool _wants_to_exit = false;
    bool _wants_to_restart = false;

   public:
    virtual ~GameFlowController() = default;

    bool wantsToExit() const;
    bool wantsToRestart() const;

    virtual void updateEvents() = 0;
    virtual void exit() = 0;
};