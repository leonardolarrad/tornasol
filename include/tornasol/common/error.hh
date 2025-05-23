#include <expected>
#include <string>
#include <string_view>

namespace sol {

class error {
public:
	error(std::string_view message) 
		: m_message(message) {}

	auto message() const -> std::string_view {
		return m_message;
	}

private:
	std::string m_message;
};

template <class T>
using result = std::expected<T, error>;

} // namespace sol