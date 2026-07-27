#include "GuiGNParams.h"

namespace mcr_Variables {
	// start, settings, exit buttons (not initially initialized)
	inline mcr_Types::ButtonsArrPtr buttons = std::make_unique<mcr_Types::ButtonsArr>();
	inline bool is_initialized = false;			// check the initialization of all buttons

	using mcr_Types::ButtonPtr;
	inline ButtonPtr start_button = nullptr;
	inline ButtonPtr settings_button = nullptr;
	inline ButtonPtr exit_button = nullptr;
}

namespace MenuCreator {	
	using namespace mcr_Variables;

	[[nodiscard]] inline ButtonPtr& get_button(const int n)	{ 
		return buttons->at(n); 
	}
	[[nodiscard]] inline mcr_Types::ButtonsArrPtr& get_all_buttons() noexcept {
		return buttons; 
	};

	template <typename Pos, typename Text>
	void init_button(const int i, const mcr_Types::ButtonSize& buttons_size,
					 Pos&& pos, Text&& text) 
	{	
		auto& button = buttons->at(i);
		button = new SimpleButton{};			
		button->button_text = text;				
		button->set_size(buttons_size);
		button->set_color(mcr_Constants::default_color);
		button[i]->set_pos(pos);
	}

	// function for initializing buttons, setting buttons' position and text 
	template <mcr_Concepts::Container PosArrType = const mcr_Types::PosArr3,
			  mcr_Concepts::Container TextArrType = const mcr_Types::TextArr3>
	void init_all_buttons(const mcr_Types::ButtonSize& buttons_size,
		const PosArrType& positions = mcr_Constants::default_positions,
		const TextArrType& texts = mcr_Constants::default_texts)
	{
		constexpr uint8_t required_length = 3;
		const auto cont_size = texts.size();

		if (cont_size != required_length)
			mcr_HelperFuncs::fatal_error(mcr_ErrorMessage::container_size_error(required_length, cont_size)); // Проверка размера

		for (uint16_t i = 0; i < cont_size; i++) {
			buttons->at(i) = std::make_unique<SimpleButton>();
			buttons->at(i)->button_text = texts[i];			
			buttons->at(i)->set_size(buttons_size);
			buttons->at(i)->set_color(mcr_Constants::default_color);
			buttons->at(i)->set_pos(positions[i]);
		}
		is_initialized = true;
	}

	template <const bool check_init = true, const bool check_range = true>
	void draw_button(sf::RenderWindow& win, const mcr_Types::ArrIndex i,
					const uint16_t text_size = 20, const sf::Color color = sf::Color::Red) 
	{
		if constexpr (check_init)
			if (!is_initialized)			// check the initialization of all buttons
				mcr_HelperFuncs::fatal_error(mcr_ErrorMessage::not_initialized);

		auto& this_button = buttons->at(i);

		this_button->draw(win, text_size, color);
	}
	
	template <const bool check_init = true, mcr_Concepts::Container cont = const mcr_Types::PosArr3>
	inline void draw_all_buttons(sf::RenderWindow& win, const uint16_t size = 20, 
		const sf::Color color = sf::Color::Red, const cont& pos = mcr_Constants::default_positions)
	{	
		for (int i = 0; i < buttons->size(); i++)
			draw_button<check_init, false>(win, i, size, color);
	}

	// NOTE: This does not check if the button is alive
	inline void del_button(const int index) {
		buttons->at(index).reset();
	}

	inline void del_all_buttons() {
		assert(is_initialized && "del_all_buttons: attempt to delete an uninitialized button\n");
		buttons.reset();
		is_initialized = false;
	}

	inline void auto_init_all_buttons(const uint16_t width, const uint16_t height) {
		const auto buttons_size = mcr_HelperFuncs::unique_button_size(width, height);
		auto buttons_position = mcr_HelperFuncs::unique_button_positions(buttons_size, width, height);
		MenuCreator::init_all_buttons(buttons_size, buttons_position);	
	}
	
	[[nodiscard]] inline sf::Text get_gui_game_name(const GuiGNParams& params)
	{
		sf::Text text{ params.font };
		text.setString(params.game_name);
		text.setCharacterSize(params.size);
		text.setFillColor(params.color);
		text.setPosition(params.pos);
		return text;
	}

	inline void draw_gui_game_name(sf::RenderWindow& window, const GuiGNParams& params)
	{
		static auto text = get_gui_game_name(params);
		window.draw(text);
	}
}