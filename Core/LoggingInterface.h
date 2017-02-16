#ifndef LOGGINGINTERFACE_H
#define LOGGINGINTERFACE_H
#include <memory>

class LoggingInterface
{
protected:
	LoggingInterface()
	{
		nextLogger = nullptr;
	}
	
	static std::unique_ptr<LoggingInterface> fInstance;
	std::unique_ptr<LoggingInterface> nextLogger;
	
	void SetNextLogger(std::unique_ptr<LoggingInterface> &params)
	{
		if( nextLogger )
		{
			nextLogger->SetNextLogger(params);
		}
		else
			nextLogger = std::move(params);
	}
public:
	
	
	LoggingInterface(const LoggingInterface&) = delete;
	
	LoggingInterface &operator=(const LoggingInterface&) = delete;
	
	template <typename T, typename ... Params>
	static void AppendSource(Params &&... params)
	{
		auto instance = std::make_unique<LoggingInterface>( params ...);
		if(!fInstance)
		{
			fInstance = std::move(instance);
		}
		else
		{
			fInstance->nextLogger(instance);
		}
	}
	virtual ~LoggingInterface();

};

#endif // LOGGINGINTERFACE_H
