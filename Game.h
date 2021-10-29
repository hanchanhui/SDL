#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "iostream"

class Game{
  public:
    
    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

    static Game* Instance(){
      if(s_pInstance == 0){
        s_pInstance = new Game();
        return s_pInstance;
      }
      return s_pInstance;
    }
    SDL_Renderer* getRenderer() const {return m_pRenderer;}

  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    SDL_Texture* m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;

    std::vector<GameObject*> m_gameObject;

    Game() {}
    static Game* s_pInstance;
    
    int m_currentFrame;
};
typedef Game TheGame;

#endif