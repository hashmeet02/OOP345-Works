#ifndef  SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <exception>

namespace sdds{
	template <typename T>
	class Collection {
		std::string m_name{};
		T* m_array{};
		size_t m_size{};
		void (*observer)(const Collection<T>& c1, const T& c2) {};
	public:
		Collection(const std::string& name) {
			m_name = name;
		}

		Collection(const Collection& toCopy) =delete;
		Collection& operator=(const Collection& toAssign)=delete;
		//Collection(Collection&& toMove) noexcept =delete;
		//Collection& operator=(Collection&& toMove) noexcept =delete;
		~Collection(){
			delete[] m_array;
			m_array = nullptr;
			m_size = 0;
		}

		const std::string& name() const {
			return m_name;
		}

		size_t size() const {
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>& c1, const T& c2)) {
			this->observer= observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool found = false;
			if (size()) {
				for (size_t i = 0; i < size(); i++) {
					if (item.title() == m_array[i].title()) {
						found = true;
					}
				}
			}
			if (!found) {
				T* temp{};
				temp = new T[size() + 1];
				for (size_t i = 0; i < size(); i++) {
					temp[i] = m_array[i];
				}
				temp[size()] = item;
				m_size++;
				delete[] m_array;
				m_array = temp;
				if (*observer != nullptr) {
					observer(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= size()) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.");
			}
			else {
				return m_array[idx];
			}
		}
		T* operator[](const std::string& title) const {
			T* temp = nullptr;
			for (size_t i = 0; i < size(); i++) {
				if (m_array[i].title() == title) {
					temp = &m_array[i];
				}
			}
			return temp;
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& collection) {
			for (size_t i = 0; i < collection.size(); i++) {
				os << collection[i]<<std::endl;
			}
			return os;
		}
	};


}
#endif // ! SDDS_COLLECTION_H
