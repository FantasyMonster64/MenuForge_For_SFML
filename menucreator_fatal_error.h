#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <format>

class Mcr_fatal_error : public std::exception {
public:
	explicit Mcr_fatal_error(const std::string&& message) : err_message("fatal error: " + message) {}
	Mcr_fatal_error(const std::string_view message)		 : err_message(std::format("Fatal error: {}", message)) {}

	inline virtual const char* what() const override {
		return err_message.c_str();
	}
	[[noreturn]] inline void call_fatal_runtime_error() {
		throw std::runtime_error(err_message);
		exit(-1);
	}

private:
	const std::string err_message;
};