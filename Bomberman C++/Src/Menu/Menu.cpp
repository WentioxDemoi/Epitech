/*
** EPITECH PROJECT, 2022
** Menu.cpp
** File description:
** Menu file for Indie Studio.
*/

#include "../Include/Menu/Menu.hpp"
#define RAYGUI_IMPLEMENTATION
#include "extras/raygui.h"


Menu::Menu()
{
    _state_music = 0;
    _state_graphic = 0;
    _option_state = 0;
    _state_game = 0;
    _state_fps = 0;
    _framesCounter = 0;
    _mouseOnText = false;
    _letterCount = 0;
    _fps = 0;
}

////////////////////////////////////////////////////////////////////////

            ////////////////// TOOLS /////////////////////

////////////////////////////////////////////////////////////////////////

std::vector<std::string> Menu::parse_txt(std::string path)
{
    std::vector<std::string> lines;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

void Menu::On_Off_Audio()
{
    if (_state_music == 0) {
    if (_buttons_audio[1].isHover() == true) {
        _shader[0].draw_shader();
        _buttons_audio[1].update();
        _shader[0].stop_shader();
        if (_buttons_audio[1].isClicked() == true) {
            _sound[0].play_audio();
            _state_music = 1;
        }
    } else
        _buttons_audio[1].draw();

    } else if (_state_music == 1) {
    if (_buttons_audio[2].isHover() == true) {
        _shader[0].draw_shader();
        _buttons_audio[2].update();
        _shader[0].stop_shader();
        if (_buttons_audio[2].isClicked() == true) {
            _sound[0].play_audio();
            _state_music = 0;
        }
    } else
        _buttons_audio[2].draw();
    }
}

void Menu::On_Off_Graphic()
{
    if (_state_graphic == 0) {
    if (_buttons_graphic[1].isHover() == true) {
        _shader[0].draw_shader();
        _buttons_graphic[1].update();
        _shader[0].stop_shader();
        if (_buttons_graphic[1].isClicked() == true) {
            _sound[0].play_audio();
            ToggleFullscreen();
            DrawFPS(1000, 10);
            _state_graphic = 1;
        }
    } else
        _buttons_graphic[1].draw();

    } else if (_state_graphic == 1) {
    if (_buttons_graphic[2].isHover() == true) {
        _shader[0].draw_shader();
        _buttons_graphic[2].update();
        _shader[0].stop_shader();
        if (_buttons_graphic[2].isClicked() == true) {
            _sound[0].play_audio();
            ToggleFullscreen();
            DrawFPS(1000, 10);
            _state_graphic = 0;
        }
    } else
        _buttons_graphic[2].draw();
    }
}

void Menu::Volume_Setter()
{
    _music_volume = GuiSliderBar(Rectangle{ 1200, 520, 200, 60}, "", NULL, _music_volume, 0, 15);
    _click_volume = GuiSliderBar(Rectangle{ 1220, 620, 200, 60}, "", NULL, _click_volume, 0, 15);
    _music[0].set_volume(_music_volume);
    _sound[0].set_volume(_click_volume);
}

void Menu::Player_Name()
{
    if (_buttons_bp[3].isHover() == true) {
        _shader[0].draw_shader();
        _buttons_bp[3].update();
        _shader[0].stop_shader();
    } else {
        _buttons_bp[3].draw(); 
    }
}

std::string Menu::Player_Name_Management()
{
  int key = GetCharPressed();

  while (key > 0)
  {
      if ((key >= 32) && (key <= 125) && (_letterCount < 7))
      {
          player_name += (char)key;
          _letterCount++;
      }
      key = GetCharPressed();
      _sound[0].play_audio();
  }
  _buttons_bp[3].AddText(player_name);

  if (player_name.length() - 1 >= 0) {
    if (IsKeyPressed(KEY_BACKSPACE)) {
        _letterCount--;
        if (_letterCount < 0) _letterCount = 0;
        player_name.erase(player_name.length() - 0.1 );
        _sound[1].play_audio();
    }
  }
  _buttons_bp[3].AddText(player_name);
  return (player_name);
}

int Menu::FPS_Management()
{
    if (_state_fps == 0) {
        if (_buttons_graphic[7].isHover() == true) {
            _shader[0].draw_shader();
            _buttons_graphic[7].update();
            _shader[0].stop_shader();
        if (_buttons_graphic[7].isClicked() == true) {
            _sound[0].play_audio();
            _state_fps = 1;
            _fps = 1;
        }
        } else
            _buttons_graphic[7].draw();

    } else if (_state_fps == 1) {
        if (_buttons_graphic[6].isHover() == true) {
            _shader[0].draw_shader();
            _buttons_graphic[6].update();
            _shader[0].stop_shader();
        if (_buttons_graphic[6].isClicked() == true) {
            _sound[0].play_audio();
            _state_fps = 0;
            _fps = 0;
        }
        } else
            _buttons_graphic[6].draw();
    }
    return (_fps);
}

int Menu::FPS_Value()
{
    return (_fps);
}

////////////////////////////////////////////////////////////////////////

void Menu::init_menu()
{
    InitAudioDevice();
    _background.push_back(Background(0, 0, "Ressources/Background/menu_background.png"));
    _background.push_back(Background(-5, -5, "Ressources/Background/end_background.png"));
    _background.push_back(Background(-5, -5, "Ressources/Background/game_background.png"));

    _shader.push_back(Shader_Indie("Ressources/Shaders/wave.fs"));
    _shader.push_back(Shader_Indie("Ressources/Shaders/depth.fs"));
    _shader.push_back(Shader_Indie("Ressources/Shaders/sobel.fs"));
    _shader[0].value_shader();

    _music.push_back(Music_G(_music_volume, "Ressources/Sound/mongus_music.mp3"));
    _music.push_back(Music_G(_music_volume, "Ressources/Sound/victory.mp3"));
    _music.push_back(Music_G(_music_volume, "Ressources/Sound/loosing.mp3"));
    _sound.push_back(Sound_G(_click_volume, "Ressources/Sound/click.wav"));
    _sound.push_back(Sound_G(_click_volume, "Ressources/Sound/kill.wav"));
    _sound.push_back(Sound_G(_click_volume, "Ressources/Sound/amogus.wav"));
    
    MenuP_Button();
    Before_Play_Button();
    Option_Button();
    Audio_Button();
    Pause_Button();
    Victory_Button();
    Loose_Button();
    Graphic_Button();
    How_To_Play_Button();
    _music[0].play_audio();
}

void Menu::event_menu()
{
    _shader[0].timer_shader();
    if (_state_music == 0) {
        _music[0].update_audio();
        _music[1].update_audio();
        _music[2].update_audio();
    } else {
    }
}

void Menu::draw_shader()
{
    if (_state_game == 0) {
        _shader[0].draw_shader();
        _background[0].draw();
        _shader[0].stop_shader();
    } else if (_state_game == 1) {
        _shader[0].draw_shader();
        _background[2].draw();
        _shader[0].stop_shader();
    } else if (_state_game == 2) {
        _shader[1].draw_shader();
        _background[0].draw();
        _shader[1].stop_shader();
    }
}

void Menu::draw_shader_victory()
{
    _shader[2].draw_shader();
    _background[1].draw();
    _shader[2].stop_shader();
}

////////////////////////////////////////////////////////////////////////
//////////////////// BUTTON INITIALISER ////////////////////////////////
////////////////////////////////////////////////////////////////////////

void Menu::MenuP_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/text.txt");

    for (int boutton = 0; boutton != 6; boutton++) {
        if (boutton == 0) {
        _buttons.push_back(Button(900, 350, 170, 73, Vector2{800, 150}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons.push_back(Button(900, 350, 170, 73, Vector2{900, 350}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons.push_back(Button(780, 500, 475, 80, Vector2{780, 500}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 3) {
        _buttons.push_back(Button(870, 650, 225, 73, Vector2{870 , 650}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 4) {
        _buttons.push_back(Button(900, 800, 160, 73, Vector2{900 , 800}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 5) {
        _buttons.push_back(Button(1680, 560, 100, 75, Vector2{1000 , 1000}, "\0", "Ressources/Text_Font/among_us.ttf"));
        } 
    }
}

void Menu::Before_Play_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/before.txt");
    
    for (int boutton = 0; boutton != 4; boutton++) {
        if (boutton == 0) {
        _buttons_bp.push_back(Button(30, 30, 170, 73, Vector2{700, 150}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_bp.push_back(Button(30, 30, 170, 73, Vector2{30, 30}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }  else if (boutton == 2) {
        _buttons_bp.push_back(Button(10000, 10000, 170, 73, Vector2{700, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }  else if (boutton == 3) {
        _buttons_bp.push_back(Button( 950, 400, 450, 75,  Vector2{950, 400}, "", "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

void Menu::How_To_Play_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/how_to_play.txt");

    for (int boutton = 0; boutton != 7; boutton++) {
        if (boutton == 0) {
        _buttons_how_to_play.push_back(Button(0, 0, 0, 0, Vector2{760, 150}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_how_to_play.push_back(Button(30, 30, 170, 73, Vector2{30, 30}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons_how_to_play.push_back(Button(0, 0, 0, 0, Vector2{650, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 3) {
        _buttons_how_to_play.push_back(Button(0, 0, 0, 0, Vector2{650 , 500}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 4) {
        _buttons_how_to_play.push_back(Button(0, 0, 0, 0, Vector2{650 , 600}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 5) {
        _buttons_how_to_play.push_back(Button(0, 0, 0, 0, Vector2{650 , 700}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 6) {
        _buttons_how_to_play.push_back(Button(0, 0, 0, 0, Vector2{650 , 800}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

void Menu::Option_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/option.txt");

    for (int boutton = 0; boutton != 4; boutton++) {
        if (boutton == 0) {
        _buttons_opt.push_back(Button(10000, 10000, 170, 73, Vector2{860, 150}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_opt.push_back(Button(30, 30, 170, 73, Vector2{30, 30}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons_opt.push_back(Button(700, 400, 220, 75, Vector2{700, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 3) {
        _buttons_opt.push_back(Button(1040, 400, 335, 75, Vector2{1040 , 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

void Menu::Audio_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/audio.txt");

    for (int boutton = 0; boutton != 7; boutton++) {
        if (boutton == 0) {
        _buttons_audio.push_back(Button(10000, 10000, 0, 0, Vector2{760, 150}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_audio.push_back(Button(910, 400, 110, 73, Vector2{940, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons_audio.push_back(Button(900, 400, 120, 73, Vector2{900, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 3) {
        _buttons_audio.push_back(Button(30, 30, 170, 75, Vector2{30 , 30}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 4) {
        _buttons_audio.push_back(Button(1040, 400, 0, 0, Vector2{600 , 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 5) {
        _buttons_audio.push_back(Button(1040, 400, 0, 0, Vector2{600 , 500}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 6) {
        _buttons_audio.push_back(Button(1040, 400, 0, 0, Vector2{600 , 600}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

void Menu::Graphic_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/graphic.txt");

    for (int boutton = 0; boutton != 8; boutton++) {
        if (boutton == 0) {
        _buttons_graphic.push_back(Button(10000, 10000, 0, 0, Vector2{690, 150}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_graphic.push_back(Button(1040, 400, 110, 73, Vector2{1040, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons_graphic.push_back(Button(1020, 400, 120, 73, Vector2{1020, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 3) {
        _buttons_graphic.push_back(Button(30, 30, 170, 75, Vector2{30 , 30}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 4) {
        _buttons_graphic.push_back(Button(1040, 400, 0, 0, Vector2{550 , 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 5) {
        _buttons_graphic.push_back(Button(1040, 400, 0, 0, Vector2{550 , 500}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 6) {
        _buttons_graphic.push_back(Button(750, 500, 120, 73, Vector2{750 , 500}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 7) {
        _buttons_graphic.push_back(Button(750, 500, 120, 73, Vector2{750 , 500}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

void Menu::Pause_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/pause.txt");

   for (int boutton = 0; boutton != 4; boutton++) {
        if (boutton == 0) {
        _buttons_pause.push_back(Button(0, 0, 0, 0, Vector2{860, 150}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_pause.push_back(Button(820, 400, 275, 73, Vector2{840, 400}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons_pause.push_back(Button(820, 500, 255, 75, Vector2{850, 500}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 3) {
        _buttons_pause.push_back(Button(730, 600, 515, 75, Vector2{730, 600}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

void Menu::Victory_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/victory.txt");

   for (int boutton = 0; boutton != 3; boutton++) {
        if (boutton == 0) {
        _buttons_victory.push_back(Button(0, 0, 0, 0, Vector2{175, 50}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_victory.push_back(Button(70, 200, 635, 73, Vector2{70, 200}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons_victory.push_back(Button(80, 300, 545, 75, Vector2{80, 300}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

void Menu::Loose_Button()
{
    std::vector<std::string> text = parse_txt("Ressources/Text/loose.txt");

   for (int boutton = 0; boutton != 3; boutton++) {
        if (boutton == 0) {
        _buttons_loose.push_back(Button(0, 0, 0, 0, Vector2{80, 50}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 1) {
        _buttons_loose.push_back(Button(80, 200, 470, 73, Vector2{80, 200}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        } else if (boutton == 2) {
        _buttons_loose.push_back(Button(80, 300, 470, 75, Vector2{80, 300}, text[boutton].c_str(), "Ressources/Text_Font/among_us.ttf"));
        }
    }
}

/////////////////////////////////////////////////////////////////
//////////////////// BUTTON DRAW ////////////////////////////////
/////////////////////////////////////////////////////////////////


int Menu::draw_button_menu()
{
    _shader[0].draw_shader();
    _buttons[0].draw();
    _shader[0].stop_shader();
   
    for (int i = 1; i != 6; i++) {
        if (_buttons[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons[i].update();
                _shader[0].stop_shader();
                if (_buttons[i].isClicked() == true) {
                    _sound[0].play_audio();
                    if (i == 2)
                        return (2);
                    else if (i == 5) {
                        _sound[2].play_audio();
                        OpenURL("https://www.innersloth.com/games/among-us/");
                    } else
                        return (i);
                }
        } else
            _buttons[i].draw();
    }

     if (_buttons[5].isHover() == true) {
        _state_game = 2;
    } else {
        _state_game = 0;
    }
    return (0);
}

int Menu::draw_button_before_play()
{
    _shader[0].draw_shader();
    _buttons_bp[0].draw();
    _shader[0].stop_shader();
    Player_Name();
    for (int i = 1; i != 4; i++) {
        if (_buttons_bp[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons_bp[i].update();
                _shader[0].stop_shader();
                if (_buttons_bp[i].isClicked() == true) {
                    _sound[0].play_audio();
                    if (i == 3) {
                        _state_game = 1;
                        return (9);
                    } else
                        return (0);
                }
        } else
            _buttons_bp[i].draw();
    }
    if (IsKeyPressed(KEY_ENTER)) {
        _state_game = 1;
        _sound[0].play_audio();
        return (9);
    }
    return (1);
}

int Menu::draw_button_how_to_play()
{
    _shader[0].draw_shader();
    _buttons_how_to_play[0].draw();
    _shader[0].stop_shader();

    for (int i = 1; i != 7; i++) {
        if (_buttons_how_to_play[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons_how_to_play[i].update();
                _shader[0].stop_shader();
                if (_buttons_how_to_play[i].isClicked() == true) {
                    _sound[0].play_audio();
                    return (0);
                }
        } else
            _buttons_how_to_play[i].draw();
    }
    return (2);
}

int Menu::draw_button_option()
{
    _shader[0].draw_shader();
    _buttons_opt[0].draw();
    _shader[0].stop_shader();
    for (int i = 1; i != 4; i++) {
        if (_buttons_opt[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons_opt[i].update();
                _shader[0].stop_shader();
                if (_buttons_opt[i].isClicked() == true) {
                    _sound[0].play_audio();
                    if (i == 2)
                        return (5);
                    else if (i == 3)
                        return (6);
                    else {
                        if (_option_state == 1)
                            return (10);
                        else
                            return (i - 1);
                    }
                }
        } else
            _buttons_opt[i].draw();
    }
    return (3);
}

int Menu::draw_button_audio()
{
    _shader[0].draw_shader();
    _buttons_audio[0].draw();
    _shader[0].stop_shader();
    
    On_Off_Audio();
    Volume_Setter();
    for (int i = 3; i != 7; i++) {
        if (_buttons_audio[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons_audio[i].update();
                _shader[0].stop_shader();
                if (_buttons_audio[i].isClicked() == true) {
                    _sound[0].play_audio();
                    return (3);
                }
        } else
            _buttons_audio[i].draw();
    }
    return (5);
}

int Menu::draw_button_graphic()
{
    _shader[0].draw_shader();
    _buttons_graphic[0].draw();
    _shader[0].stop_shader();
    
    On_Off_Graphic();
    _fps = FPS_Management();
    for (int i = 3; i != 6; i++) {
        if (_buttons_graphic[i].isHover() == true) {
                _shader[0].draw_shader();
               _buttons_graphic[i].update();
                _shader[0].stop_shader();
                if (_buttons_graphic[i].isClicked() == true) {
                    _sound[0].play_audio();
                    return (3);
                }
        } else
            _buttons_graphic[i].draw();
    }
    return (6);
}

int Menu::draw_button_pause()
{
    _shader[0].draw_shader();
    _buttons_pause[0].draw();
    _shader[0].stop_shader();

    _state_game = 0;

    for (int i = 1; i != 4; i++) {
        if (_buttons_pause[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons_pause[i].update();
                _shader[0].stop_shader();
                if (_buttons_pause[i].isClicked() == true) {
                    _sound[0].play_audio();
                    if (i == 1) {
                        _state_game = 1;
                        return (9);
                    } else if (i == 2) {
                        _option_state = 1;
                        return (3);
                    } else {
                        _option_state = 0;
                        return (0);
                    }
                }
        } else
            _buttons_pause[i].draw();
    }
    return (10);
}

int Menu::draw_button_victory()
{
    _shader[0].draw_shader();
    _buttons_victory[0].draw();
    _shader[0].stop_shader();

    _music[0].stop_audio();
    _music[1].play_audio();

    for (int i = 1; i != 3; i++) {
        if (_buttons_victory[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons_victory[i].update();
                _shader[0].stop_shader();
                if (_buttons_victory[i].isClicked() == true) {
                    _sound[0].play_audio();
                    if (i == 1) {
                        _music[1].stop_audio();
                        _music[0].play_audio();
                        return (9);
                    } else {
                        _music[1].stop_audio();
                        _music[0].play_audio();
                        _state_game = 0;
                        return (0);
                    }
                }
        } else
            _buttons_victory[i].draw();
    }
    return (11);
}

int Menu::draw_button_loose()
{
    _shader[0].draw_shader();
    _buttons_loose[0].draw();
    _shader[0].stop_shader();

    _music[0].stop_audio();
    _music[2].play_audio();


    for (int i = 1; i != 3; i++) {
        if (_buttons_loose[i].isHover() == true) {
                _shader[0].draw_shader();
                _buttons_loose[i].update();
                _shader[0].stop_shader();
                if (_buttons_loose[i].isClicked() == true) {
                    _sound[0].play_audio();
                    if (i == 1) {
                        _music[2].stop_audio();
                        _music[0].play_audio();
                        return (9);
                    } else {
                        _music[2].stop_audio();
                        _music[0].play_audio();
                        _state_game = 0;
                        return (0);
                    }
                }
        } else
            _buttons_loose[i].draw();
    }
    return (12);
}